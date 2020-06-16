#include <VulcanCannon.h>
#include <logger.h>

namespace gradiusnx {
	std::vector<Projectile*> Weapon::fire(void)
	{
		Logger::getInstance().log(Logger::INFO, "Pew!!");
		std::vector<Projectile*> projectiles;
		Projectile* projectile = projectileTemplate->clone();
		projectile->getEntityProperties().setXpos(200);
		projectile->getEntityProperties().setYpos(200);
		projectiles.push_back(projectile);
		spawnProjectiles(projectiles);
		return projectiles;
	}
}
