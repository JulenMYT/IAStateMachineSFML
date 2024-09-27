#include "FriendlySquare.h"

#include "EntityFlashState.h"
#include "EntityFollowState.h"
#include "EntityIdleState.h"

void FriendlySquare::Initialize()
{
	entityStateMachine = GetOwner()->CreateComponent<EntityStateMachine>();
	entityIdleState = GetOwner()->CreateState<EntityIdleState>(this, entityStateMachine);
	entityFollowState = GetOwner()->CreateState<EntityFollowState>(this, entityStateMachine);
	entityFlashState = GetOwner()->CreateState<EntityFlashState>(this, entityStateMachine);

	entityStateMachine->Initialize(entityIdleState);

	player = GetOwner()->GetOwner()->FindGameObject("Player");
}

void FriendlySquare::Update(float _delta_time)
{
	isInFollowRange = followRange->CheckCollision(*player->GetComponent<RectangleCollider>());
	isInFlashRange = flashRange->CheckCollision(*player->GetComponent<RectangleCollider>());

	entityStateMachine->GetState()->Update(_delta_time);
}
