#ifndef PLAYER_H_
#define PLAYER_H_

#include <flat.h>
#include <switch.h>

class Player : public flat2d::Entity
{
private:
    float speed = 10;
    float joystickValFactor = 0.001; // Raw joytick values seem to high to be used
    float getMinJoyValue(void) { return SDL_JOYSTICK_AXIS_MIN * joystickValFactor * speed; }
    float getMaxJoyValue(void) { return SDL_JOYSTICK_AXIS_MAX * joystickValFactor * speed; }

public:
    Player(int x, int y) : Entity(x, y, 128, 128)
    {
        entityProperties.setCollidable(true);
        setInputHandler(true);
    }
    void init(const flat2d::GameData *gameData) override;
    void handle(const SDL_Event &event) override;
};

#endif // PLAYER_H_