#pragma once

#include <iostream>
#include <stdlib.h> 

#include "Variables.h"
#include "Movementcomponent.h"

class Aggression
{

private:

	EntityAgressionStatus typeOfAgression;
	double totalAgressionTime;
	double baseAgressTimeGap = 0.f;

	double currentAgressionTime = 0.f;
	double currenRestTime = 0.f;

	sf::Vector2f currentAgressOutput;

public:

	bool hasEnded = false;

	// initializer


	// constructor/destructor
	Aggression(EntityAgressionStatus typeOfAgression, double totalAgressionTime, double baseAgressTimeGap);
	~Aggression();

	// updates
	void update(const float& dt, sf::Vector2f thisVelocity, sf::Vector2f playerPosition);

	// getters
	EntityAgressionStatus getType() { return typeOfAgression; };
	sf::Vector2f getCurrentAgressOutput() { return currentAgressOutput; };

};

