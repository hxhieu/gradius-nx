#ifndef WEAPON_H_
#define WEAPON_H_

#include <Projectile.h>
#include <flat.h>
#include <logger.h>

namespace gradiusnx {
	class Weapon
	{
	  private:
		Projectile* projectileTemplate;
		int wave = 1;
		int spread = 1;
		const flat2d::GameData* gameData;

	  protected:
		void spawnProjectiles(const std::vector<Projectile*> projectiles)
		{
			flat2d::EntityContainer* entityContainer =
			  gameData->getEntityContainer();
			for (auto& proj : projectiles) {
				Logger::getInstance().log(Logger::INFO, proj->name);
				entityContainer->registerObject(proj);
			}
		}

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
		std::vector<Projectile*> fire(void);
		void stop(void);
		~Weapon() { delete projectileTemplate; }
	};
}

#endif // WEAPON_H_
