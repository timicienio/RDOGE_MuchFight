#pragma once

#include <iostream>
#include <stdlib.h> 

#include "Variables.h"
#include "Movementcomponent.h"

class Aggression
{

private:

	EntityAgressionStatus typeOfAgression;
	float totalAgressionTime;
	float baseAgressTimeGap = 0.f;

	float currentAgressionTime = 0.f;
	float currenRestTime = 0.f;

	sf::Vector2f currentAgressOutput;

public:

	bool hasEnded = false;

	// initializer


	// constructor/destructor
	Aggression(EntityAgressionStatus typeOfAgression, float totalAgressionTime, float baseAgressTimeGap);
	~Aggression();

	// updates
	void update(const float& dt, sf::Vector2f thisVelocity, sf::Vector2f playerPosition);

	// getters
	EntityAgressionStatus getType() { return typeOfAgression; };
	sf::Vector2f getCurrentAgressOutput() { return currentAgressOutput; };

};

