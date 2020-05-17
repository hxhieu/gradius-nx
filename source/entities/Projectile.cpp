#include <Projectile.h>

Projectile *Projectile::clone(void)
{
    return new Projectile(spriteClip, impactClip, explosionClip, speed);
}