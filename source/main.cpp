#include <iostream>
#include <flat.h>
#include <logger.h>

int main(int argc, char *argv[])
{
    Logger::getInstance().log(Logger::DEBUG, "Loading Flat");
    flat2d::FlatBuilder *flat = new flat2d::FlatBuilder();
    flat->loadSDL("Flat Demo", 60, 800, 600);
    flat2d::GameEngine *engine = flat->getGameEngine();
    Logger::getInstance().flush();

    flat2d::EntityContainer *container = flat->getGameData()->getEntityContainer();
    // You can register your objects to the container here. Objects extend the Entity class in flat

    // Create the callback methods
    auto stateCallback = [](flat2d::GameData *gameData) -> flat2d::GameStateAction {
        return flat2d::GameStateAction::NOOP;
    };
    auto handleCallback = [](const SDL_Event &event) -> void {
        // Nothing to do here
    };

    Logger::getInstance().log(Logger::DEBUG, "Starting the engine");
    // stateCallback and handleCallback can be omitted if you don't need them
    engine->run(stateCallback, handleCallback);
    Logger::getInstance().log(Logger::DEBUG, "Exiting");

    delete flat;
}