#include <logger.h>
#include <entities/Player.h>
#include <game/TextureAtlas.h>

void Player::init(const flat2d::GameData *gameData)
{
    Logger::getInstance().log(Logger::INFO, "init Player");
    setTexture(TextureAtlas::getInstance().getTex());
    addAnimation("idle", new flat2d::Animation(TextureAtlas::PLAYER_IDLE, 200));
    addAnimation("rollUp", new flat2d::Animation(TextureAtlas::PLAYER_ROLL_UP, 200, true));
    addAnimation("rollDown", new flat2d::Animation(TextureAtlas::PLAYER_ROLL_DOWN, 200, true));
    startAnimation("rollDown");
}