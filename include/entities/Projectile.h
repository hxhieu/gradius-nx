#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include <cassert>
#include <flat.h>

namespace gradiusnx {
	class Projectile : public flat2d::Entity
	{
	  private:
		flat2d::Clips spriteClip;
		flat2d::Clips impactClip;
		flat2d::Clips explosionClip;
		float speed = 10;

	  public:
		Projectile(flat2d::Clips* sprite,
		           float speed,
		           flat2d::Clips* impact = nullptr,
		           flat2d::Clips* explosion = nullptr)
		  : Entity(0, 0, 0, 0)
		{
			// Sprite is required
			assert(!sprite->empty());
			spriteClip = *sprite;
			if (impact)
				impactClip = *impact;
			if (explosion)
				explosionClip = *explosion;
			speed = speed;
			entityProperties.setWidth(spriteClip.front().w);
			entityProperties.setHeight(spriteClip.front().h);
			entityProperties.setCollidable(true);
		};
		Projectile* clone(void);
	};
}
#endif // PROJECTILE_H_
