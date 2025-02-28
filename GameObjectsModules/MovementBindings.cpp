#include "MovementBindings.h"

using namespace GameObjMod;

MovementBindings::MovementBindings(Player& player) : player(player) { }

auto MovementBindings::GetOnKeyPressed() {
	return [&player = this->player](const sf::Event::MouseButtonPressed& button) {
		if (button.button == sf::Mouse::Button::Left) {

		}
		};
}

auto MovementBindings::GetOnMouseButtonPressed() {
	return [&player = this->player](const sf::Event::KeyPressed& button) {
		if (button.scancode == sf::Keyboard::Scancode::D) {

		}
		if (button.scancode == sf::Keyboard::Scancode::A) {

		}
		};
}