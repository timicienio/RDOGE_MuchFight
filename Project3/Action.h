#pragma once

#include <iostream>
#include "Variables.h"
#include "Movementcomponent.h"

class Action
{
private:

	EntityActionStatus typeOfAction;

	double totalActionTime;
	double currentActionTime = 0.f;
	double jumpTime;

	double treadRestTime = 3.f;
	double currentRestTime = 4.f;

	sf::Vector2f currentChaseTargetPosition;

	sf::Vector2f currentMovementOutput;


public:

	bool hasEnded = false;
	bool hasJumped = true;

	bool hasTreadIntention;

	Action(EntityActionStatus typeOfAction, double totalActionTime, double jumpTime, bool hasTreadIntention);
	~Action();

	//Updates
	void update(const float& dt, sf::Vector2f position);

	//Getters
	EntityActionStatus getType() { return typeOfAction; };
	sf::Vector2f getCurrentMovementOutput() { return currentMovementOutput; };

	//Setters
	void setChaseTargetPosition(sf::Vector2f coordinate);
};

