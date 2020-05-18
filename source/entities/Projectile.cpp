#include <Projectile.h>

namespace gradiusnx {
	Projectile* Projectile::clone(void)
	{
		return new Projectile(spriteClip, impactClip, explosionClip, speed);
	}
}
