#include "RectangleRenderer.h"
#include <iostream>

#include "SFML/Graphics/Shape.hpp"

RectangleRenderer::RectangleRenderer()
{
	shape = new sf::RectangleShape();
}

RectangleRenderer::~RectangleRenderer()
{
	delete shape;
	shape = nullptr;
}

void RectangleRenderer::Render(sf::RenderWindow* _window)
{
	const GameObject* owner = GetOwner();

	const Maths::Vector2<float> position = owner->GetPosition();
	shape->setPosition(position.x - size.x / 2.0f, position.y - size.y / 2.0f);

	shape->setSize(static_cast<sf::Vector2f>(owner->GetScale() * size));
	shape->setRotation(owner->GetRotation());

	shape->setFillColor(color);

	_window->draw(*shape);
}