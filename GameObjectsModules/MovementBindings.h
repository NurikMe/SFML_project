#pragma once

#include "../GameObjects/Player.h";

using namespace GameObjects;

namespace GameObjMod {
	class MovementBindings {
	public:
		MovementBindings();

		//functions for Events
		auto GetOnMouseButtonPressed();
		auto GetOnKeyPressed();

	private:
	};
}