#include "Player.h"

using namespace GameObjects;

Player::Player(std::unique_ptr<sf::RectangleShape> body,
	GameObjState state,
	std::unordered_map<GameObjState, std::unique_ptr<sf::Texture>> textures,
	sf::Vector2f speed,
	sf::Vector2<unsigned int> index,
	GameObjFace face,
	Animation* animation) : GameObject(std::move(body), state, textures, speed, index, face),
	animation(animation), movement(MovementBindings(*this)) { }

Player::Player(const Player& player) : GameObject(std::move(body), state, textures, speed, index, face),
animation(animation), movement(MovementBindings(*this)) { }

void Player::Update(float deltaTime) {

}

void Player::Draw(sf::RenderWindow window) {
	window.draw(*body.get());
}