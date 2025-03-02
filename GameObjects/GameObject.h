#pragma once

#include "Enums/GameObjState.h"
#include "Enums/GameObjFace.h"
#include<unordered_map>
#include <SFML\Graphics.hpp>

using namespace Enums;

namespace GameObjects {
	class GameObject {
	public:
		GameObject(std::unique_ptr<sf::RectangleShape> body,
			GameObjState state,
			std::unordered_map<GameObjState, std::unique_ptr<sf::Texture>> textures,
			sf::Vector2f speed,
			sf::Vector2<unsigned int> index,
			GameObjFace face
		) : body{ std::move(body) },
			state(state), 
			textures(std::move(textures)), 
			speed(speed),
			index(index),
			face(face) { }

		GameObject(GameObject&& object) noexcept 
										: body{ std::move(object.body) }, 
										  state(object.state),  
										  textures{ std::move(textures) },
										  speed(object.speed),
										  index(object.index),
										  face(object.face) { }

		GameObject(GameObject& object) = delete;

		virtual void Update(float deltaTime) = 0;
		virtual void Draw(sf::RenderWindow& window) = 0;

	protected:
		std::unique_ptr<sf::RectangleShape> body;
		GameObjState						state;
		std::unordered_map<GameObjState, std::unique_ptr<sf::Texture>> textures;
		sf::Vector2f						speed;
		sf::Vector2<unsigned int>			index;
		GameObjFace							face;
	};
}