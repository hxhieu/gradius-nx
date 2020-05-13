#ifndef PLAYER_H_
#define PLAYER_H_

#include <flat.h>

class Player : public flat2d::Entity
{
private:
public:
    Player(int x, int y) : Entity(x, y, 128, 128)
    {
        entityProperties.setCollidable(true);
        setInputHandler(true);
    }
    void init(const flat2d::GameData *gameData) override;
};

#endif // PLAYER_H_