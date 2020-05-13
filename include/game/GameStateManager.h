#ifndef GAMESTATEMANAGER_H_
#define GAMESTATEMANAGER_H_

#include <flat.h>
#include <GameState.h>

class GameStateManager
{
private:
    // TODO: Splash screen https://github.com/LiquidityC/justdontdie/blob/master/src/SplashScreen.h
    GameState currentState = GAME;
    void loadGame(flat2d::GameData *gameData);
    void loadSplash(flat2d::GameData *gameData);
    bool isQuiting = false;

public:
    GameStateManager();
    virtual ~GameStateManager() {}

    void handleEvent(const SDL_Event &event);
    bool handleGame(flat2d::GameData *gameData);
    void run(flat2d::GameData *gameData);
    bool quit();
};

#endif // GAMESTATEMANAGER_H_