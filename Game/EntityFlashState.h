#pragma once

#include "EntityState.h"
#include "FriendlySquare.h"

class EntityFlashState : public EntityState
{
public :
	EntityFlashState(FriendlySquare* _entity, EntityStateMachine* _entityStateMachine);

	void Update(float _delta_time) override;
};
