#pragma once

#include "../GameObjects/Player.h";

using namespace GameObjects;

namespace GameObjMod {
	class MovementBindings {
	public:
		MovementBindings(Player& player);

		//functions for Events
		auto GetOnMouseButtonPressed();
		auto GetOnKeyPressed();

	private:
		Player player;
	};
}