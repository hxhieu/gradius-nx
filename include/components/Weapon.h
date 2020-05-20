#ifndef WEAPON_H_
#define WEAPON_H_

#include <Projectile.h>

namespace gradiusnx {
	class Weapon
	{
	  private:
		Projectile* projectileTemplate;
		int wave = 1;
		int spread = 1;

	  public:
		Weapon(Projectile* projectile, int waveCount, int spreadCount)
		{
			projectileTemplate = projectile;
			wave = waveCount;
			spread = spreadCount;
		}
		std::vector<Projectile>* fire(void);
		void stop(void);
		~Weapon() { delete projectileTemplate; }
	};
}

#endif // WEAPON_H_
