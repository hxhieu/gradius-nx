#include <entities/Player.h>
#include <game/TextureAtlas.h>
#include <logger.h>

namespace gradiusnx {
	void Player::init(const flat2d::GameData* gameData)
	{
		Logger::getInstance().log(Logger::INFO, "init Player");
		setTexture(TextureAtlas::getInstance().getTex());
		addAnimation("idle",
		             new flat2d::Animation(TextureAtlas::PLAYER_IDLE, 200));
		addAnimation(
		  "rollUp",
		  new flat2d::Animation(TextureAtlas::PLAYER_ROLL_UP, 200, true));
		addAnimation(
		  "rollDown",
		  new flat2d::Animation(TextureAtlas::PLAYER_ROLL_DOWN, 200, true));
		startAnimation("idle");
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
					if (value < 0) {
						startAnimation("rollUp");
					} else if (value > 0) {
						startAnimation("rollDown");
					} else {
						startAnimation("idle");
					}
					entityProperties.setYvel(value * speed);
				}
				break;
			}
				// TODO: Support DPAD
				// case SDL_JOYBUTTONDOWN:
				// {
				//     // TODO: Not supporting detach joycons i.e. only use
				//     #0 attached joycons if (event.jbutton.which != 0)
				//         return;
				//     int btn = event.jbutton.button;
				//     if (btn == HidcfgButtonConfig_DLeft)
				//     {
				//         entityProperties.setXvel(getMinJoyValue());
				//     }
				//     else if (btn == HidcfgButtonConfig_DRight)
				//     {
				//         entityProperties.setXvel(getMaxJoyValue());
				//     }

				//     if (btn == HidcfgButtonConfig_DUp)
				//     {
				//         entityProperties.setYvel(getMinJoyValue());
				//     }
				//     else if (btn == HidcfgButtonConfig_DDown)
				//     {
				//         entityProperties.setYvel(getMaxJoyValue());
				//     }
				//     break;
				// }
				// case SDL_JOYBUTTONUP:
				// {
				//     // TODO: Not supporting detach joycons i.e. only use
				//     #0 attached joycons if (event.jbutton.which != 0)
				//         return;
				//     int btn = event.jbutton.button;
				//     if (btn == HidcfgButtonConfig_DLeft || btn ==
				//     HidcfgButtonConfig_DRight)
				//     {
				//         entityProperties.setXvel(0);
				//     }
				//     if (btn == HidcfgButtonConfig_DUp || btn ==
				//     HidcfgButtonConfig_DDown)
				//     {
				//         entityProperties.setYvel(0);
				//     }
				//     break;
				// }

			default:
				break;
		}
	}
}
