#pragma once

#include "../Enums/GameObjFace.h"
#include "../Enums/GameObjState.h"
#include <SFML/Graphics.hpp>;

using namespace Enums;
using namespace GameObjects;

namespace Builders {
	template<typename T, typename V>
	class GameObjectBuilder {
	public:
		//Property setters
		virtual T& SetBodySize(sf::Vector2f&& size) = 0;
		virtual T& SetState(GameObjState&& state) = 0;
		virtual T& SetTextures(std::unordered_map<GameObjState, std::unique_ptr<sf::Texture>>& textures) = 0;
		virtual T& SetSpeed(sf::Vector2f&& speed) = 0;
		virtual T& SetIndex(sf::Vector2<unsigned int>&& index) = 0;
		virtual T& SetFace(GameObjFace&& face) = 0;

		//build is valid only if Body and Textures are provided
		virtual V build() = 0;

	protected:
		std::unique_ptr<sf::RectangleShape> body = nullptr;
		GameObjState						state = GameObjState::Idle;
		std::unordered_map<GameObjState, std::unique_ptr<sf::Texture>> textures;
		sf::Vector2f						speed = {10.0f, 10.0f};
		sf::Vector2<unsigned int>			index = { 0, 0 };
		GameObjFace							face = GameObjFace::Right;
	};
}
