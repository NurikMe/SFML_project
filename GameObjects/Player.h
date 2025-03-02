#pragma once

#include "GameObject.h"
#include "../GameObjectsModules/Animation.h"
#include "../GameObjectsModules/MovementBindings.h"
#include <unordered_map>
#include <SFML\Graphics.hpp>

using namespace GameObjMod;

namespace GameObjects {
	class Player : GameObject {
	public:
		Player(std::unique_ptr<sf::RectangleShape> body,
			GameObjState state,
			std::unordered_map<GameObjState, std::unique_ptr<sf::Texture>> textures,
			sf::Vector2f speed,
			sf::Vector2<unsigned int> index,
			GameObjFace face,
			Animation* animation
		);

		Player(Player&& player);

		void Update(float deltaTime) override;
		void Draw(sf::RenderWindow& window) override;

		//getters and setters
		GameObjState getState();
		void setState(GameObjState state);

		GameObjFace getFace();
		void setFace(GameObjFace state);

		sf::RectangleShape getBody();
		void setBody(sf::RectangleShape& body);

	private:
		Animation* animation;
		//MovementBindings movement;
	};
}