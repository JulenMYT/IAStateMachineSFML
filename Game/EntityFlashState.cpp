#include "EntityFlashState.h"

#include "EntityFollowState.h"

EntityFlashState::EntityFlashState(FriendlySquare* _entity, EntityStateMachine* _entityStateMachine): EntityState(_entity, _entityStateMachine) {}

void EntityFlashState::Update(float _deltaTime)
{
	if (!entity->isInFlashRange)
	{
		entityStateMachine->ChangeState(entity->entityFollowState);
	}
}
