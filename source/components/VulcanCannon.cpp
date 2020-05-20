#include <VulcanCannon.h>
#include <logger.h>

namespace gradiusnx {
	std::vector<Projectile>* Weapon::fire(void)
	{
		Logger::getInstance().log(Logger::INFO, "Pew!!");
	}
}
