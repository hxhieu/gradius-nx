#include <Projectile.h>

namespace gradiusnx {
	Projectile* Projectile::clone(void)
	{
		// TODO: memory leak
		return new Projectile(&spriteClip, speed, &impactClip, &explosionClip);
	}

	// void Projectile::preMove(const flat2d::GameData* gameData)
	// {
	// 	entityProperties.setXvel(1);
	// }

	// void Projectile::render(const flat2d::RenderData* data) const
	// {
	// 	SDL_SetRenderDrawColor(data->getRenderer(), 0xFF, 0x00, 0x00, 0xFF);
	// 	const flat2d::EntityProperties::Areas currentAreas =
	// 	  entityProperties.getCurrentAreas();
	// 	for (auto it = currentAreas.begin(); it != currentAreas.end(); it++) {
	// 		SDL_Rect bounds = (*it).asSDLRect();
	// 		bounds.x = data->getCamera()->getScreenXposFor(bounds.x);
	// 		bounds.y = data->getCamera()->getScreenYposFor(bounds.y);
	// 		SDL_RenderDrawRect(data->getRenderer(), &bounds);
	// 	}
	// 	Entity::render(data);
	// }
}
