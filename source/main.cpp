#include <flat.h>
#include <game/GameStateManager.h>
#include <game/TextureAtlas.h>
#include <iostream>
#include <logger.h>
#include <switch.h>

int
main(int argc, char* argv[])
{
	Logger::getInstance().log(Logger::INFO, "init romfs");
	romfsInit();

	Logger::getInstance().log(Logger::INFO, "init engine");
	flat2d::FlatBuilder* flat = new flat2d::FlatBuilder();
	flat->loadSDL("GradiusNX", 60, 1280, 720);
	flat2d::GameEngine* engine = flat->getGameEngine();

	gradiusnx::TextureAtlas::getInstance().load(
	  flat->getGameData()->getRenderData()->getRenderer());

	gradiusnx::GameStateManager* gameState = new gradiusnx::GameStateManager();
	gameState->run(flat->getGameData());

	// Create the callback methods
	auto stateCallback =
	  [&gameState](flat2d::GameData* gameData) -> flat2d::GameStateAction {
		if (gameState->quit()) {
			return flat2d::GameStateAction::QUIT;
		}
		return flat2d::GameStateAction::NOOP;
	};

	auto handleCallback = [&gameState](const SDL_Event& event) -> void {
		gameState->handleEvent(event);
	};

	Logger::getInstance().log(Logger::INFO, "start game loop");

	// stateCallback and handleCallback can be omitted if you don't need them
	engine->run(stateCallback, handleCallback);

	Logger::getInstance().log(Logger::INFO, "QUIT");
	// Final flush
	Logger::getInstance().flush();
						Logger::getInstance().cleanup();

	romfsExit();

	delete flat;
			}
