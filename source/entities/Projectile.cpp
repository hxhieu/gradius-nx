#include <Projectile.h>

namespace gradiusnx {
	Projectile* Projectile::clone(void)
	{
		// TODO: memory leak
		return new Projectile(&spriteClip, speed, &impactClip, &explosionClip);
	}
}
