#pragma once

#include "EntityState.h"
#include "FriendlySquare.h"

class EntityFollowState : public EntityState
{
public :
	EntityFollowState(FriendlySquare* _entity, EntityStateMachine* _entityStateMachine);

	void Update(float _delta_time) override;

private :
	Maths::Vector2f direction;
	float speed = 100.0f;

	Maths::Vector2f CheckDirection();

	Maths::Vector2<float> Move(const float _delta_time);

	bool CheckCollision(const Maths::Vector2<float>& newPosition) const;
};
