#include <iostream>
#include <logger.h>
#include <flat.h>
#include <game/GameStateManager.h>

int main(int argc, char *argv[])
{
    Logger::getInstance().log(Logger::DEBUG, "init engine");
    flat2d::FlatBuilder *flat = new flat2d::FlatBuilder();
    flat->loadSDL("GradiusNX", 60, 1280, 720);
    flat2d::GameEngine *engine = flat->getGameEngine();

    GameStateManager *gameState = new GameStateManager();
    gameState->run(flat->getGameData());

    // Create the callback methods
    auto stateCallback = [&gameState](flat2d::GameData *gameData) -> flat2d::GameStateAction {
        if (gameState->quit())
        {
            return flat2d::GameStateAction::QUIT;
        }
        return flat2d::GameStateAction::NOOP;
    };

    auto handleCallback = [&gameState](const SDL_Event &event) -> void {
        gameState->handleEvent(event);
    };

    Logger::getInstance().log(Logger::DEBUG, "start game loop");

    // stateCallback and handleCallback can be omitted if you don't need them
    engine->run(stateCallback, handleCallback);

    Logger::getInstance().log(Logger::DEBUG, "QUIT");
    // Final flush
    Logger::getInstance().flush();

    delete flat;
}