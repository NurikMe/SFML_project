#pragma once

#include "../Enums/GameObjFace.h"
#include "../GameObjects/Player.h"
#include "GameObjectBuilder.h";

using namespace GameObjects;

namespace Builders {
	class PlayerBuilder final : GameObjectBuilder<PlayerBuilder, Player> {
	public:
		//ctors
		PlayerBuilder();

		//virtual methods
		PlayerBuilder& SetBodySize(sf::Vector2f&& body) override;
		PlayerBuilder& SetState(GameObjState&& state) override;
		PlayerBuilder& SetTextures(std::unordered_map<GameObjState, std::unique_ptr<sf::Texture>>& textures) override;
		PlayerBuilder& SetSpeed(sf::Vector2f&& speed) override;
		PlayerBuilder& SetIndex(sf::Vector2<unsigned int>&& index) override;
		PlayerBuilder& SetFace(GameObjFace&& face) override;
		
		//throws exception if Body and Textures are not specified
		Player build() override;

		//Class specific methods
		PlayerBuilder& SetAnimation(Animation& animation);
	private:
		Animation* animation;
	};
}