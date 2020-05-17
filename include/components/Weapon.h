#ifndef WEAPON_H_
#define WEAPON_H_

#include <Projectile.h>

class Weapon
{
private:
    Projectile *projectileSample;
    int wave = 1;
    int spread = 1;

public:
    void useProjectile(Projectile *projectile);
    std::vector<Projectile> *fire(void);
};

#endif // WEAPON_H_