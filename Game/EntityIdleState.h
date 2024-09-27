#pragma once

#include "EntityState.h"
#include "FriendlySquare.h"

#include <iostream>

class EntityIdleState : public EntityState
{
public :
	EntityIdleState(FriendlySquare* _entity, EntityStateMachine* _entityStateMachine) : EntityState(_entity, _entityStateMachine) {}

	void Update(float _delta_Time) override
	{
		std::cout << "Je idle" << '\n';

		if (entity->isInFollowRange)
		{
			entityStateMachine->ChangeState(reinterpret_cast<EntityState*>(entity->entityFollowState));
		}
	}
};
