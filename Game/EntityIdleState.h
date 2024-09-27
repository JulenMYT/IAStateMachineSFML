#pragma once

#include "EntityState.h"
#include "FriendlySquare.h"

class EntityIdleState : public EntityState 
{
public :
	EntityIdleState(FriendlySquare* _entity, EntityStateMachine* _entityStateMachine) : EntityState(_entity, _entityStateMachine) {}

	void Update(float _deltaTime) override
	{
		if (entity->isInFollowRange)
		{
			entityStateMachine->ChangeState(reinterpret_cast<EntityState*>(entity->entityFollowState));
		}
	}
};