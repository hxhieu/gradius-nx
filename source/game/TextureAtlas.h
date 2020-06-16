#ifndef TEXTUREATLAS_H_
#define TEXTUREATLAS_H_

#include <GameState.h>
#include <flat.h>

namespace gradiusnx {
	class TextureAtlas
	{
	  private:
		flat2d::Texture* texture = new flat2d::Texture(); // TODO: memory leak

	  public:
		// All animations
		// NOTE: Frame start from the back to front
		inline static std::vector<SDL_Rect> PLAYER_IDLE = { { 0, 0, 64, 64 } };
		inline static std::vector<SDL_Rect> PLAYER_ROLL_UP = {
			{ 128, 0, 64, 64 },
			{ 64, 0, 64, 64 }
		};
		inline static std::vector<SDL_Rect> PLAYER_ROLL_DOWN = {
			{ 256, 0, 64, 64 },
			{ 192, 0, 64, 64 }
		};

		inline static std::vector<SDL_Rect> PROJECTILE_VULCAN_STRAIGHT = {
			{ 320, 0, 64, 64 },
			{ 384, 0, 64, 64 }
		};

		static TextureAtlas& getInstance(void)
		{
			static TextureAtlas mAtlas;
			return mAtlas;
		}

		flat2d::Texture* getTex(void);
		void load(SDL_Renderer* renderer);
	};
}
#endif // TEXTUREATLAS_H_
