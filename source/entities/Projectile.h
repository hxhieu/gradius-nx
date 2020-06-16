#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include <TextureAtlas.h>
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
			setTexture(TextureAtlas::getInstance().getTex());
			// TODO: memory leak
			addAnimation("idle", new flat2d::Animation(*sprite, 200));
			if (impact) {
				impactClip = *impact;
				addAnimation("impact", new flat2d::Animation(*impact, 200));
			}
			if (explosion) {
				explosionClip = *explosion;
				addAnimation("explosion",
				             new flat2d::Animation(*explosion, 200));
			}
			speed = speed;
			entityProperties.setWidth(sprite->front().w);
			entityProperties.setHeight(sprite->front().h);
			entityProperties.setCollidable(true);

			startAnimation("idle");
		};
		Projectile* clone(void);
		std::string name;
	};
}
#endif // PROJECTILE_H_
