#include "EntityStateMachine.h"

#include "EntityIdleState.h"
#include "EntityFollowState.h"
#include "EntityFlashState.h"

inline void EntityStateMachine::Initialize(EntityState* startingState)
{
	currentState = startingState;
	currentState->EnterState();
}

inline void EntityStateMachine::ChangeState(EntityState* newState)
{
	currentState->ExitState();
	currentState = newState;
	currentState->EnterState();
}
