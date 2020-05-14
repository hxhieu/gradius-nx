#include <flat.h>
#include <logger.h>
#include <switch.h>

#include <game/GameStateManager.h>
#include <entities/Player.h>

GameStateManager::GameStateManager()
{
    Logger::getInstance().log(Logger::INFO, "init GameStateManager");
}

void GameStateManager::handleEvent(const SDL_Event &event)
{
    switch (event.type)
    {
    case SDL_JOYBUTTONDOWN:
        // https://github.com/devkitPro/SDL/blob/switch-sdl2/src/joystick/switch/SDL_sysjoystick.c#L52
        // seek for joystick #0
        if (event.jbutton.which == 0)
        {
            // Looks like libnx has it wrong way round
            if (event.jbutton.button == HidcfgButtonConfig_Plus)
            {
                // (-) button down
                // Manual flush the logs for debugging
                Logger::getInstance().flush();
            }
            else if (event.jbutton.button == HidcfgButtonConfig_Minus)
            {
                // (+) button down, quit the game
                isQuiting = true;
                Logger::getInstance().flush();
            }
        }
        break;

    default:
        break;
    }
}

bool GameStateManager::handleGame(flat2d::GameData *gameData)
{
    // TODO:
    return true;
}

void GameStateManager::loadGame(flat2d::GameData *gameData)
{
    flat2d::EntityContainer *entityContainer = gameData->getEntityContainer();
    entityContainer->registerObject(new Player(200, 200));

    // You can register your objects to the container here. Objects extend the Entity class in flat
}

void GameStateManager::loadSplash(flat2d::GameData *gameData)
{
    // TODO:
}

void GameStateManager::run(flat2d::GameData *gameData)
{
    switch (currentState)
    {
    case SPLASH:
        loadSplash(gameData);
        break;
    case GAME:
    default:
        loadGame(gameData);
        break;
    }
}

bool GameStateManager::quit()
{
    return isQuiting;
}