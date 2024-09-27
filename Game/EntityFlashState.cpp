#include "EntityFlashState.h"

#include "EntityFollowState.h"
#include "RectangleRenderer.h"
#include <iostream>

EntityFlashState::EntityFlashState(FriendlySquare* _entity, EntityStateMachine* _entityStateMachine): EntityState(_entity, _entityStateMachine) {}

void EntityFlashState::Update(float _delta_time)
{
	std::cout << "Je flash" << '\n';

	entity->GetOwner()->GetComponent<RectangleRenderer>()->SetColor(sf::Color::Red);

	if (!entity->isInFlashRange)
	{
		entityStateMachine->ChangeState(entity->entityFollowState);
	}
}
