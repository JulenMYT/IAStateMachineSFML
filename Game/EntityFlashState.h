#pragma once

#include "EntityState.h"
#include "FriendlySquare.h"

class EntityFlashState : public EntityState
{
public :
	EntityFlashState(FriendlySquare* _entity, EntityStateMachine* _entityStateMachine) : EntityState(_entity, _entityStateMachine) {}

	void Update(float _deltaTime) override
	{
		if (!entity->isInFlashRange)
		{
			entityStateMachine->ChangeState(reinterpret_cast<EntityState*>(entity->entityFollowState));
		}
	}
};