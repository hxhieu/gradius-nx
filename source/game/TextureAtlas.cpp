#include <Logger.h>
#include <flat.h>
#include <game/TextureAtlas.h>

namespace gradiusnx {
	flat2d::Texture* TextureAtlas::getTex(void) { return texture; }

	void TextureAtlas::load(SDL_Renderer* renderer)
	{
		std::string texturePath = "romfs:/spritesheet.png";
		Logger::getInstance().log(Logger::INFO, "try loading " + texturePath);
		bool success = texture->loadFromFile(texturePath, renderer);
		if (!success) {
			Logger::getInstance().log(
			  Logger::ERROR, "Fail to load atlas texture: " + texturePath);
		}
	}
}
