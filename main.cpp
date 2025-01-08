#include "imgui.h"
#include "imgui-SFML.h"

#include "SFML/Graphics.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Window Title");
    ImGui::SFML::Init(window);
    
    sf::CircleShape shape(200.f, 100);
    shape.setFillColor(sf::Color(204, 77, 5)); // Color circle
    shape.setPosition({ 200, 200 }); // Center circle

    sf::Clock deltaClock;
    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            ImGui::SFML::ProcessEvent(window, *event);
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Window Title");
        ImGui::Text("Window Text!");
        ImGui::End();

        window.clear(sf::Color(18, 33, 43)); // Color background
        window.draw(shape);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}