//STL headers
#include <iostream>
#include <thread>
#include <chrono>

//ImGui headers
#include "imgui.h"
#include "imgui-SFML.h"

//SFML headers
#include "SFML/Graphics.hpp"

//Custom headers
#include "GameObjects/Builders/PlayerBuilder.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode({ 512, 512 }), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
	sf::View view({ 0.0f , 0.0f }, { 256, 256 });

	/*sf::Texture playerRunTexture;
	sf::Texture playerIdleTexture;
	sf::Texture playerTurnTexture;
	playerRunTexture.loadFromFile("120x80_PNGSheets\\_Run.png");
	playerIdleTexture.loadFromFile("120x80_PNGSheets\\_Idle.png");
	playerTurnTexture.loadFromFile("120x80_PNGSheets\\_TurnAround.png");*/
	std::unordered_map<GameObjState, std::unique_ptr<sf::Texture>> textures;
	std::unique_ptr<sf::Texture> text1 = std::make_unique<sf::Texture>("120x80_PNGSheets\\_Idle.png");
	textures.try_emplace(Enums::GameObjState::Idle, std::move(text1));
	std::unique_ptr<sf::Texture> text2 = std::make_unique<sf::Texture>("120x80_PNGSheets\\_Run.png");
	textures.try_emplace(Enums::GameObjState::Run, std::move(text2));
	std::unique_ptr<sf::Texture> text3 = std::make_unique<sf::Texture>("120x80_PNGSheets\\_TurnAround.png");
	textures.try_emplace(Enums::GameObjState::Turn, std::move(text3));

	sf::RectangleShape player({ 120.0f, 80.0f });
	//player.setTexture(&playerIdleTexture);
	player.setOrigin(player.getSize() / 2.0f);

	Builders::PlayerBuilder playerBuilder;
	playerBuilder.SetTextures(textures);
	playerBuilder.SetBodySize({ 120.0f, 80.0f });
	playerBuilder.SetState(Enums::GameObjState::Idle);
	playerBuilder.SetSpeed({ 20.0, 20.0 });
	playerBuilder.SetIndex({ 0, 0 });
	playerBuilder.SetFace(Enums::GameObjFace::Right);

	Player player1 = playerBuilder.build();

	//Animation animation(playerRunTexture, { 10 , 1 }, 0.1f);

	float deltaTime = 0.0f;
	//GameObjects::Player player(playerTexture, sf::Vector2u(10, 1), 0.1f, 20);
	sf::Clock clock;

	const auto onClosed = [&window](const sf::Event::Closed) {
		window.close();
		};

	const auto onResized = [&window](const sf::Event::Resized& newSize) {
		std::cout << "New size: x = " << newSize.size.x << ", y = " << newSize.size.y << "\n";
		window.setSize(newSize.size);
		};

	const auto onTextEntered = [](const sf::Event::TextEntered& newText) {
		if (newText.unicode < 128) {
			printf("%c", newText.unicode);
		}
		};

	const auto onKeyPressed = [&player, &player1](const sf::Event::KeyPressed& key) {
		if (key.scancode == sf::Keyboard::Scancode::A) {
			player1.setState(GameObjState::Run);
			player1.setFace(GameObjFace::Left);

			/*player.move({ -1.0f, 0.0f });
			if (player.getScale().x != -1) {
				player.setScale({ -1, 1 });
				player.setPosition({ player.getPosition().x + player.getSize().x, player.getPosition().y });
			}*/
		}
		if (key.scancode == sf::Keyboard::Scancode::D) {
			player1.setState(GameObjState::Run);
			player1.setFace(GameObjFace::Right);

			/*player.move({ 1.0f, 0.0f });
			if (player.getScale().x != 1) {
				player.setScale({ 1, 1 });
				player.setPosition({ player.getPosition().x - player.getSize().x, player.getPosition().y });
			}*/
		}
		if (key.scancode == sf::Keyboard::Scancode::S) {
			player.move({ 0.0f, 1.0f });
		}
		if (key.scancode == sf::Keyboard::Scancode::W) {
			player.move({ 0.0f, -1.0f });
		}
		};

	const auto onKeyReleased = [&player, &player1](const sf::Event::KeyReleased& key) {
		player1.setState(GameObjState::Idle);
		};

	const auto onMouseButtonPressed = [&player](const sf::Event::MouseButtonPressed& button) {
		if (button.button == sf::Mouse::Button::Left) {
			player.setPosition({ (float)button.position.x - player.getGeometricCenter().x ,
								 (float)button.position.y - player.getGeometricCenter().y });
		}
		};

	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();

		window.handleEvents(onClosed, onResized, onTextEntered, onKeyPressed, onKeyReleased, onMouseButtonPressed);

		player1.Update(deltaTime);

		//player.setTextureRect(animation.uvRect);

		//view.setCenter(player.getPosition());
		window.clear();
		//window.setView(view);
		player1.Draw(window);
		//window.draw(player);
		window.display();

		std::this_thread::sleep_for(std::chrono::duration<double, std::milli> (1000.0f / 24.0f));
	}


	//sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Window Title");
	//ImGui::SFML::Init(window);
	//
	//sf::CircleShape shape(200.f, 100);
	//shape.setFillColor(sf::Color(204, 77, 5)); // Color circle
	//shape.setPosition({ 200, 200 }); // Center circle

	//sf::Clock deltaClock;
	//while (window.isOpen())
	//{
	//    while (const auto event = window.pollEvent())
	//    {
	//        ImGui::SFML::ProcessEvent(window, *event);
	//        if (event->is<sf::Event::Closed>())
	//            window.close();
	//    }
	//    ImGui::SFML::Update(window, deltaClock.restart());

	//    ImGui::Begin("Window Title");
	//    ImGui::Text("Window Text!");
	//    ImGui::End();

	//    window.clear(sf::Color(18, 33, 43)); // Color background
	//    window.draw(shape);
	//    ImGui::SFML::Render(window);
	//    window.display();
	//}

	//ImGui::SFML::Shutdown();
	return 0;
}