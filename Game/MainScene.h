#pragma once

#include "Scene.h"
#include "GameObject.h"
#include "MovementComponent.h"
#include "RectangleRenderer.h"

class MainScene : public Scene
{
public :
	MainScene() : Scene("MainScene")
	{
		CreatePlayer("Player", 200.0f, 200.0f, 100.0f, 100.0f, sf::Color::Red);

	}

	GameObject* CreatePlayer(const std::string& _name, const float _position_x, const float _position_y, const float size_x = 100.0f, const float size_y = 100.0f, const sf::Color color = sf::Color::Red)
	{
		GameObject* gameObject = CreateGameObject(_name);
		gameObject->SetPosition(Maths::Vector2f(_position_x, _position_y));

		gameObject->CreateComponent<MovementComponent>();

		RectangleRenderer* rectangleRenderer = gameObject->CreateComponent<RectangleRenderer>();
		rectangleRenderer->SetSize(Maths::Vector2f(size_x,size_y));
		rectangleRenderer->SetColor(color);

		return gameObject;
	}
};