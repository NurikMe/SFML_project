#pragma once

#include "../GameObjects/Enums/GameObjFace.h"
#include "SFML/Graphics.hpp"

using namespace Enums;

namespace GameObjMod {
	class Animation {
	public:
		//variables
		sf::IntRect uvRect;

		//functions
		Animation(sf::Texture& texture, sf::Vector2u imageCount, float switchTime);
		~Animation();

		void Update(float deltaTime, GameObjFace face);

	private:
		//variables
		sf::Vector2u imageCount;
		sf::Vector2u currentImage;
		sf::Texture texture;

		float totalTime;
		float switchTime;
	};
}
