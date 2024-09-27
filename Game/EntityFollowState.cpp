#include "EntityFollowState.h"

#include "EntityFlashState.h"
#include "EntityIdleState.h"

EntityFollowState::EntityFollowState(FriendlySquare* _entity, EntityStateMachine* _entityStateMachine): EntityState(_entity, _entityStateMachine) {}

void EntityFollowState::Update(float _delta_time)
{
	if (!entity->isInFollowRange)
	{
		entityStateMachine->ChangeState(entity->entityIdleState);
	}
	else if (entity->isInFlashRange)
	{
		entityStateMachine->ChangeState((entity->entityFlashState));
	}

	Maths::Vector2<float> newPosition = Move(_delta_time);

	if (!CheckCollision(newPosition))
	{
		entity->GetOwner()->SetPosition(newPosition);
	}
}

Maths::Vector2f EntityFollowState::CheckDirection()
{
	direction = entity->GetOwner()->GetPosition() - entity->player->GetPosition();
	direction = direction.Normalize();
	return direction;
}

Maths::Vector2<float> EntityFollowState::Move(const float _delta_time)
{
	CheckDirection();

	Maths::Vector2<float> position = entity->GetOwner()->GetPosition();
	position += direction * speed * _delta_time;
	entity->GetOwner()->SetPosition(position);

	return position;
}

bool EntityFollowState::CheckCollision(const Maths::Vector2<float>& newPosition) const
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
