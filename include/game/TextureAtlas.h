#ifndef TEXTUREATLAS_H_
#define TEXTUREATLAS_H_

#include <flat.h>
#include <GameState.h>

class TextureAtlas
{
private:
    flat2d::Texture *texture = new flat2d::Texture();

public:
    // All animations
    inline static std::vector<SDL_Rect> PLAYER_IDLE = {{128, 0, 64, 64}};
    inline static std::vector<SDL_Rect> PLAYER_ROLL_UP = {{64, 0, 64, 64}, {192, 0, 64, 64}};
    inline static std::vector<SDL_Rect> PLAYER_ROLL_DOWN = {{256, 0, 64, 64}, {0, 0, 64, 64}};

    static TextureAtlas &getInstance(void)
    {
        static TextureAtlas mAtlas;
        return mAtlas;
    }

    flat2d::Texture *getTex(void);
    void load(SDL_Renderer *renderer);
};

#endif // TEXTUREATLAS_H_