#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include "Component.h"

class GradientBackground : public Component
{
public:
    GradientBackground()
        : topColor(sf::Color::Blue), bottomColor(sf::Color::Cyan) {}

    GradientBackground(const sf::Color& topColor, const sf::Color& bottomColor)
        : topColor(topColor), bottomColor(bottomColor) {}

    void Render(sf::RenderWindow* _window) override
    {
        drawGradient(_window);
    }

private:
    sf::Color topColor;
    sf::Color bottomColor;

    void drawGradient(sf::RenderWindow* _window)
    {
        sf::VertexArray gradient(sf::TrianglesStrip, 4);

        gradient[0].position = sf::Vector2f(0, 0);
        gradient[0].color = topColor;

        gradient[1].position = sf::Vector2f(0, _window->getSize().y);
        gradient[1].color = bottomColor;

        gradient[2].position = sf::Vector2f(_window->getSize().x, 0);
        gradient[2].color = topColor;

        gradient[3].position = sf::Vector2f(_window->getSize().x, _window->getSize().y);
        gradient[3].color = bottomColor;

        _window->draw(gradient);
    }
};
