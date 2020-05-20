#ifndef PLAYER_H_
#define PLAYER_H_

#include <Weapon.h>
#include <flat.h>
#include <switch.h>

namespace gradiusnx {
	class Player : public flat2d::Entity
	{
	  private:
		float speed = 10;
		// Raw joytick values seem to high to be used
		float joystickValFactor = 0.001;
		// Max 3 weapons, for now
		std::vector<Weapon*> weapons = { nullptr, nullptr, nullptr };

		float getMinJoyValue(void)
		{
			return SDL_JOYSTICK_AXIS_MIN * joystickValFactor * speed;
		}
		float getMaxJoyValue(void)
		{
			return SDL_JOYSTICK_AXIS_MAX * joystickValFactor * speed;
		}

	  public:
		Player(int x, int y)
		  : Entity(x, y, 128, 128)
		{
			entityProperties.setCollidable(true);
			setInputHandler(true);
		}
		void init(const flat2d::GameData* gameData) override;
		void handle(const SDL_Event& event) override;
		void setWeapon(Weapon* weapon, int index);

		~Player()
		{
			// TODO: possible memory leak
			weapons.clear();
		}
	};
}
#endif // PLAYER_H_
