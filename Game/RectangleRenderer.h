#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

#include "Component.h"

class RectangleRenderer : public Component
{
public:
	RectangleRenderer();
	~RectangleRenderer() override;

	void SetColor(const sf::Color& _color) { color = _color; }

	Maths::Vector2f GetSize() const { return size; }
	void SetSize(const Maths::Vector2f& _size) { size = _size; }

	void Render(sf::RenderWindow* _window) override;

private:
	sf::Color color = sf::Color::White;
	Maths::Vector2f size;

	sf::RectangleShape* shape = nullptr;
};