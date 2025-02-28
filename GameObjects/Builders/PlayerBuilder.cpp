#include "PlayerBuilder.h"
#include "..//Exceptions/ReqPropsNotSpecified.h"

using namespace Builders;

PlayerBuilder::PlayerBuilder() {
	animation = nullptr;
}

PlayerBuilder& PlayerBuilder::SetBodySize(sf::Vector2f&& size) {
	this->body = std::make_unique<sf::RectangleShape>(new sf::RectangleShape(size));
	this->body->setOrigin(size / 2.0f);
	return *this;
}

PlayerBuilder& PlayerBuilder::SetState(GameObjState&& state) {
	this->state = state;
	return *this;
}

PlayerBuilder& PlayerBuilder::SetTextures(std::unordered_map<GameObjState, std::unique_ptr<sf::Texture>>& textures) {
	this->textures = std::move(textures);
	return *this;
}

PlayerBuilder& PlayerBuilder::SetSpeed(sf::Vector2f&& speed) {
	this->speed = speed;
	return *this;
}

PlayerBuilder& PlayerBuilder::SetIndex(sf::Vector2<unsigned int>&& index) {
	this->index = index;
	return *this;
}

PlayerBuilder& PlayerBuilder::SetFace(GameObjFace&& face) {
	this->face = face;
	return *this;
}

PlayerBuilder& PlayerBuilder::SetAnimation(Animation& animation) {
	this->animation = &animation;
	return *this;
}

Player PlayerBuilder::build() {
	if (body == nullptr || textures.empty()) {
		throw Exceptions::ReqPropsNotSpecified();
	}

	return Player(std::move(body), state, std::move(textures), speed, index, face, animation);
}

