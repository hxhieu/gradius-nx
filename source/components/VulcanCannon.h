#ifndef VULCANCANNON_H_
#define VULCANCANNON_H_

#include <TextureAtlas.h>
#include <Weapon.h>

namespace gradiusnx {
	class VulcanCannon : public Weapon
	{
	  private:
	  public:
		VulcanCannon(const flat2d::GameData* gameData)
		  : Weapon(new Projectile(
		             &TextureAtlas::getInstance().PROJECTILE_VULCAN_STRAIGHT,
		             20),
		           2,
		           1,
		           gameData)
		{}
	};
}

#endif // VULCANCANNON_H_
