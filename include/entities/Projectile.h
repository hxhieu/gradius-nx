#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include <cassert>
#include <flat.h>

class Projectile : public flat2d::Entity
{
private:
    std::vector<SDL_Rect> spriteClip;
    std::vector<SDL_Rect> impactClip;
    std::vector<SDL_Rect> explosionClip;
    float speed = 10;

public:
    Projectile(std::vector<SDL_Rect> sprite, std::vector<SDL_Rect> impact, std::vector<SDL_Rect> explosion, float speed)
        : Entity(0, 0, 0, 0)
    {
        assert(!sprite.empty());
        spriteClip = sprite;
        impactClip = impact;
        explosionClip = explosion;
        speed = speed;
        entityProperties.setWidth(sprite.front().w);
        entityProperties.setHeight(sprite.front().h);
        entityProperties.setCollidable(true);
    };
    Projectile *clone(void);
};

#endif // PROJECTILE_H_