#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include <EntityBase.h>
#include <TextureAtlas.h>
#include <cassert>

namespace gradiusnx {
	class Projectile : public EntityBase
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
		  : EntityBase(0, 0)
		{
			// Sprite is required
			assert(!sprite->empty());
			spriteClip = *sprite;
			setTexture(TextureAtlas::getInstance().getTex());
			// TODO: memory leak
			addAnimation("idle", new flat2d::Animation(*sprite, 100));
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
			entityProperties.setXvel(speed);
			// entityProperties.setCollidable(true);

			startAnimation("idle");
		};
		Projectile* clone(void);
		// void preMove(const flat2d::GameData* gameData) override;
	};
}
#endif // PROJECTILE_H_
