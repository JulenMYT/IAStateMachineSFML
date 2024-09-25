#pragma once

#include "Component.h"
#include "InputManager.h"

class MovementComponent : public Component
{
public :

	void Update(const float _delta_time) override
	{
		Input(_delta_time);
	}

	void Input(const float _delta_time)
	{
		Maths::Vector2<float> position = GetOwner()->GetPosition();

		if (InputManager::GetKey(sf::Keyboard::D))
		{
			position.x += speed * _delta_time;
		}
		if (InputManager::GetKey(sf::Keyboard::Q))
		{
			position.x -= speed * _delta_time;
		}

		if (InputManager::GetKey(sf::Keyboard::Z))
		{
			position.y -= speed * _delta_time;
		}
		if (InputManager::GetKey(sf::Keyboard::S))
		{
			position.y += speed * _delta_time;
		}

		GetOwner()->SetPosition(position);
	}

private :
	float speed = 500.0f;
};