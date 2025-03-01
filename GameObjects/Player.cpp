#include "Player.h"

using namespace GameObjects;

Player::Player(std::unique_ptr<sf::RectangleShape> body,
	GameObjState state,
	std::unordered_map<GameObjState, std::unique_ptr<sf::Texture>> textures,
	sf::Vector2f speed,
	sf::Vector2<unsigned int> index,
	GameObjFace face,
	Animation* animation) : GameObject(std::move(body), state, textures, speed, index, face),
	animation(animation) { }

Player::Player(const Player& player) : GameObject(std::move(body), state, textures, speed, index, face),
animation(animation) { }

GameObjState Player::getState() {
	return this->state;
}

void Player::setState(GameObjState state) {
	if (this->state != state) {
		this->state = state;

		sf::Vector2u imageCount;
		if (state == GameObjState::Idle) {
			imageCount = sf::Vector2u(10, 1);
		}
		else if (state == GameObjState::Run) {
			imageCount = sf::Vector2u(10, 1);
		}
		else if (state == GameObjState::Turn) {
			imageCount = sf::Vector2u(3, 1);
		}

		this->index = {0, 1};
		this->animation = new Animation(*this->textures.find(state)->second.get(), imageCount, 0.1f);
	}
}

GameObjFace Player::getFace() {
	return this->face;
}

void Player::setFace(GameObjFace face) {
	if (this->face != face) {
		this->face = face;

		if (this->face == GameObjFace::Left) {
			if (this->body->getScale().x != -1) {
				this->body->setScale({ -1, 1 });
				this->body->setPosition({ this->body->getPosition().x + this->body->getSize().x, this->body->getPosition().y });
			}
		}
		else {
			if (this->body->getScale().x != 1) {
				this->body->setScale({ 1, 1 });
				this->body->setPosition({ this->body->getPosition().x - this->body->getSize().x, this->body->getPosition().y });
			}
		}
	}
}

void Player::Update(float deltaTime) {
	if (this->face == GameObjFace::Left) {
		this->body->move({ -(this->speed.x/deltaTime), 0.0f });
	}
	else {
		this->body->move({ (this->speed.x/deltaTime), 0.0f });
	}

	animation->Update(deltaTime, this->face);
}

void Player::Draw(sf::RenderWindow& window) {
	window.draw(*body.get());
}