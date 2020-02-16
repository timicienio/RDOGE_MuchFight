#pragma once

#include <iostream>
#include "Variables.h"
#include "Movementcomponent.h"

class Action
{
private:

	EntityActionStatus typeOfAction;

	float totalActionTime;
	float currentActionTime = 0.f;
	float jumpTime;

	float treadRestTime = 3.f;
	float currentRestTime = 4.f;

	sf::Vector2f currentChaseTargetPosition;

	sf::Vector2f currentMovementOutput;


public:

	bool hasEnded = false;
	bool hasJumped = true;

	bool hasTreadIntention;

	Action(EntityActionStatus typeOfAction, float totalActionTime, float jumpTime, bool hasTreadIntention);
	~Action();

	//Updates
	void update(const float& dt, sf::Vector2f position);

	//Getters
	EntityActionStatus getType() { return typeOfAction; };
	sf::Vector2f getCurrentMovementOutput() { return currentMovementOutput; };

	//Setters
	void setChaseTargetPosition(sf::Vector2f coordinate);
};

