#pragma once

#include "Scene.h"
#include "GameObject.h"
#include "MovementComponent.h"
#include "RectangleRenderer.h"
#include "Camera.h"
#include "RectangleCollider.h"
#include "RectangleTrigger.h"
#include "Background.h"

class MainScene : public Scene
{
public :
	MainScene() : Scene("MainScene")
	{
		CreateBackground();

		CreatePlayer("Player", 200.0f, 200.0f, 50.0f, 50.0f, sf::Color::Red);

		CreateDebile("Debile", 300.0f, 300.0f, 75.0f, 75.0f, 200.0f, 50.0f, sf::Color::Green);
	}

	GameObject* CreateBackground()
	{
		GameObject* gameObject = CreateGameObject("Background");
		GradientBackground* gradientBackground = gameObject->CreateComponent<GradientBackground>();

		return gameObject;
	}

	GameObject* CreatePlayer(const std::string& _name, const float _position_x, const float _position_y, const float size_x = 100.0f, const float size_y = 100.0f, const sf::Color color = sf::Color::Red)
	{
		GameObject* gameObject = CreateGameObject(_name);
		gameObject->SetPosition(Maths::Vector2f(_position_x, _position_y));

		Camera* camera = gameObject->CreateComponent<Camera>();

		RectangleRenderer* rectangleRenderer = gameObject->CreateComponent<RectangleRenderer>();
		rectangleRenderer->SetSize(Maths::Vector2f(size_x,size_y));
		rectangleRenderer->SetColor(color);
		rectangleRenderer->SetOrigin(Maths::Vector2f(size_x / 2.0f, size_y / 2.0f));

		RectangleCollider* rectangleCollider = gameObject->CreateComponent<RectangleCollider>();
		rectangleCollider->SetBounds(sf::FloatRect(_position_x, _position_y, size_x, size_y));

		MovementComponent* movementComponent = gameObject->CreateComponent<MovementComponent>();
		movementComponent->SetCollider(rectangleCollider);

		return gameObject;
	}

	GameObject* CreateDebile(const std::string& _name, const float _position_x, const float _position_y, const float size_x = 100.0f, const float size_y = 100.0f, const float chaseRange = 100, const float tauntRange = 50.0f, const sf::Color color = sf::Color::Red)
	{
		GameObject* gameObject = CreateGameObject(_name);
		gameObject->SetPosition(Maths::Vector2f(_position_x, _position_y));

		RectangleRenderer* rectangleRenderer = gameObject->CreateComponent<RectangleRenderer>();
		rectangleRenderer->SetSize(Maths::Vector2f(size_x, size_y));
		rectangleRenderer->SetColor(color);
		rectangleRenderer->SetOrigin(Maths::Vector2f(size_x / 2.0f, size_y / 2.0f));

		RectangleCollider* rectangleCollider = gameObject->CreateComponent<RectangleCollider>();
		rectangleCollider->SetBounds(sf::FloatRect(_position_x, _position_y, size_x, size_y));

		RectangleTrigger* chaseTrigger = gameObject->CreateComponent<RectangleTrigger>();
		chaseTrigger->SetBounds(sf::FloatRect(_position_x - chaseRange, _position_y - chaseRange, size_x + chaseRange * 2, size_y + chaseRange * 2));

		RectangleTrigger* tauntTrigger = gameObject->CreateComponent<RectangleTrigger>();
		tauntTrigger->SetBounds(sf::FloatRect(_position_x - tauntRange, _position_y - tauntRange, size_x + tauntRange * 2, size_y + tauntRange * 2));

		return gameObject;
	}
};
