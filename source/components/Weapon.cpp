#include <Weapon.h>

namespace gradiusnx {
	std::vector<Projectile*> Weapon::fire(int x, int y)
	{
		std::vector<Projectile*> projectiles;
		Projectile* projectile = projectileTemplate->clone();
		projectile->setCenter(x, y);
		projectiles.push_back(projectile);
		spawnProjectiles(projectiles);
		return projectiles;
	}
}
