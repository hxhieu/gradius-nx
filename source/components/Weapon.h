#ifndef WEAPON_H_
#define WEAPON_H_

#include <Logger.h>
#include <Projectile.h>
#include <flat.h>

namespace gradiusnx {
	class Weapon
	{
	  private:
		Projectile* projectileTemplate;
		int wave = 1;
		int spread = 1;
		const flat2d::GameData* gameData;
		void spawnProjectiles(const std::vector<Projectile*> projectiles)
		{
			flat2d::EntityContainer* entityContainer =
			  gameData->getEntityContainer();
			for (auto& proj : projectiles) {
				entityContainer->registerObject(proj);
			}
		}

	  protected:
	  public:
		Weapon(Projectile* projectile,
		       int waveCount,
		       int spreadCount,
		       const flat2d::GameData* gd)
		{
			projectileTemplate = projectile;
			wave = waveCount;
			spread = spreadCount;
			gameData = gd;
		}
		std::vector<Projectile*> fire(int x, int y);
		void stop(void);
		~Weapon() { delete projectileTemplate; }
	};
}

#endif // WEAPON_H_
