#pragma once

#include "Component.h"

class FriendlySquare;
class EntityStateMachine;

class EntityState : public Component
{
public :
	EntityState(FriendlySquare* _entity, EntityStateMachine* _entityStateMachine)
	{
		entity = _entity;
		entityStateMachine = _entityStateMachine;
	}

	virtual void EnterState() {}

	virtual void ExitState() {}

	void Update(float _delta_time) override {}

protected :
	FriendlySquare* entity;
	EntityStateMachine* entityStateMachine;
};
