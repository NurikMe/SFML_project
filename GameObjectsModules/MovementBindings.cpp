#include "MovementBindings.h"

using namespace GameObjMod;

MovementBindings::MovementBindings(){ }

auto MovementBindings::GetOnKeyPressed() {
	return [](const sf::Event::MouseButtonPressed& button) {
		if (button.button == sf::Mouse::Button::Left) {

		}
		};
}

auto MovementBindings::GetOnMouseButtonPressed() {
	return [](const sf::Event::KeyPressed & button) {
		if (button.scancode == sf::Keyboard::Scancode::D) {

		}
		if (button.scancode == sf::Keyboard::Scancode::A) {

		}
		};
}