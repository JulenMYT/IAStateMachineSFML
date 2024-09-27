#pragma once

#include "EntityState.h"
#include "FriendlySquare.h"
#include "RectangleCollider.h"

class EntityFollowState : public EntityState
{
public :
	EntityFollowState(FriendlySquare* _entity, EntityStateMachine* _entityStateMachine) : EntityState(_entity, _entityStateMachine) {}

	void Update(float _delta_time) override
	{
		if (!entity->isInFollowRange)
		{
			entityStateMachine->ChangeState(reinterpret_cast<EntityState*>(entity->entityIdleState));
		}
		else if (entity->isInFlashRange)
		{
			entityStateMachine->ChangeState(reinterpret_cast<EntityState*>(entity->entityFlashState));
		}

		Maths::Vector2<float> newPosition = Move(_delta_time);

		if (!CheckCollision(newPosition))
		{
			entity->GetOwner()->SetPosition(newPosition);
		}
	}

private :
	Maths::Vector2f direction;
	float speed = 100.0f;

	Maths::Vector2f CheckDirection()
	{
		direction = entity->GetOwner()->GetPosition() - entity->player->GetPosition();
		direction = direction.Normalize();
		return direction;
	}

	Maths::Vector2<float> Move(const float _delta_time)
	{

		CheckDirection();

		Maths::Vector2<float> position = entity->GetOwner()->GetPosition();
		position += direction * speed * _delta_time;
		entity->GetOwner()->SetPosition(position);

		return position;
	}

	bool CheckCollision(const Maths::Vector2<float>& newPosition) const
	{
		RectangleCollider* rectangleCollider = entity->GetOwner()->GetComponent<RectangleCollider>();
		sf::FloatRect tempBounds = rectangleCollider->GetBounds();
		tempBounds.left = newPosition.x - tempBounds.width / 2.0f;
		tempBounds.top = newPosition.y - tempBounds.height / 2.0f;

		const auto& colliders = RectangleCollider::GetColliders();
		for (const auto& collider : colliders)
		{
			if (collider != rectangleCollider && collider->GetBounds().intersects(tempBounds))
			{
				return true;
			}
		}

		return false;
	}
};