#include <Logger.h>
#include <Player.h>
#include <TextureAtlas.h>
#include <VulcanCannon.h>

namespace gradiusnx {
	void Player::init(const flat2d::GameData* gameData)
	{
		Logger::getInstance().log(Logger::INFO, "init Player");
		setTexture(TextureAtlas::getInstance().getTex());
		// TODO: memory leak
		addAnimation("idle",
		             new flat2d::Animation(TextureAtlas::PLAYER_IDLE, 200));
		// TODO: memory leak
		addAnimation(
		  "rollUp",
		  new flat2d::Animation(TextureAtlas::PLAYER_ROLL_UP, 200, true));
		// TODO: memory leak
		addAnimation(
		  "rollDown",
		  new flat2d::Animation(TextureAtlas::PLAYER_ROLL_DOWN, 200, true));
		// TODO: memory leak
		attachWeapon(new VulcanCannon(gameData), 0);
		startAnimation("idle");
	}

	void Player::attachWeapon(Weapon* weapon, int index)
	{
		if (index < weapons.size()) {
			weapons[index] = weapon;
		}
	}

	void Player::handle(const SDL_Event& event)
	{
		// TODO: Seperate movement component?
		// https://github.com/devkitPro/SDL/blob/switch-sdl2/src/joystick/switch/SDL_sysjoystick.c#L52
		switch (event.type) {
			case SDL_JOYAXISMOTION: {
				int value =
				  event.jaxis.value *
				  joystickValFactor; // raw values might be too big to use
				int axis = event.jaxis.axis;
				if (axis == SDL_CONTROLLER_AXIS_LEFTX) {
					entityProperties.setXvel(value * speed);
				} else if (event.jaxis.axis == SDL_CONTROLLER_AXIS_LEFTY) {
					if (value < -5) {
						startAnimation("rollUp");
					} else if (value > 5) {
						startAnimation("rollDown");
					} else {
						startAnimation("idle");
					}
					entityProperties.setYvel(value * speed);
				}
				break;
			}

			case SDL_JOYBUTTONDOWN: {
				// TODO: Not supporting detach joycons i.e. only use #0 attached
				// joycons
				if (event.jbutton.which != 0)
					return;
				int btn = event.jbutton.button;

				if (btn == HidcfgButtonConfig_Y) {
					weapons[0]->fire(getCentreX(), getCentreY());
				}

				// TODO: Support DPAD
				// if (btn == HidcfgButtonConfig_DLeft) {
				// 	entityProperties.setXvel(getMinJoyValue());
				// } else if (btn == HidcfgButtonConfig_DRight) {
				// 	entityProperties.setXvel(getMaxJoyValue());
				// }

				// if (btn == HidcfgButtonConfig_DUp) {
				// 	entityProperties.setYvel(getMinJoyValue());
				// } else if (btn == HidcfgButtonConfig_DDown) {
				// 	entityProperties.setYvel(getMaxJoyValue());
				// }
				break;
			}
			case SDL_JOYBUTTONUP: {
				// TODO: Not supporting detach joycons i.e. only use # 0
				// attached joycons
				if (event.jbutton.which != 0)
					return;
				int btn = event.jbutton.button;

				// TODO: Support DPAD
				// if (btn == HidcfgButtonConfig_DLeft ||
				//     btn == HidcfgButtonConfig_DRight) {
				// 	entityProperties.setXvel(0);
				// }
				// if (btn == HidcfgButtonConfig_DUp ||
				//     btn == HidcfgButtonConfig_DDown) {
				// 	entityProperties.setYvel(0);
				// }
				break;
			}

			default:
				break;
		}
	}
}
