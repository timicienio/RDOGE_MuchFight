#pragma once

#include <random>
#include <iostream>

#include "Entities.h"

#include "Action.h"
#include "Agression.h"

#include "Variables.h"

class AutomationComponent
{
private:
	//// Variables

	// Component References


	// Behavior Parameters

	// Action

	double idelTimeGapAvg;
	double idelTimeGapRange;

	double moveTimeGapAvg;
	double moveTimeGapRange;


	// The chance of the entity decide to move towards left when wandering
	double leftChance;
	// The chance of the entity decide to jump in every movement
	double jumpChance;
	// The chance of the entity chasing the player instead of wandering
	double chaseChance;

	// If this entity has the intention of treading the player
	bool hasTreadIntention;

	// Agression

	double restTimeGapAvg;
	double restTimeGapRange;

	double agressTimeGapAvg;
	double agressTimeGapRange;

	double baseAgressTimeGap;

	double lightChance;
	double heavyChance;
	double allOutChance;
	

	// Status
	EntityActionStatus actionStatus;
	
	Action* currentAction;
	Agression* currentAgression;


	// Timers
	double timeSinceSpawn;

	// Random
	std::random_device rd;
	std::default_random_engine gen = std::default_random_engine(rd());

	std::uniform_real_distribution<double> distribution{ 0.0, 1.0 };
	std::uniform_real_distribution<double> distributionNeg{ -1.0, 1.0 };

	////Functions
	//Initializer
	void initVariables(double idelTimeAvg, double idelTimeRange, double moveTimeAvg, double moveTimeRange, double leftChance, double jumpChance, double chaseChance, bool hasTreadIntention);

	void initAgressionVariables(double restTimeGapAvg, double restTimeGapRange, double agressTimeGapAvg, double agressTimeGapRange, double baseAgressTimeGap, double lightChance, double heavyChance, double allOutChance);

	// Action
	void createAction();

	// Agression
	void createAgression();

public:
	//Constructor/Destructor
	AutomationComponent(double idelTimeAvg, double idelTimeRange, double moveTimeAvg, double moveTimeRange, double leftChance, double jumpChance, double chaseChance, bool hasTreadIntention, double restTimeGapAvg, double restTimeGapRange, double agressTimeGapAvg, double agressTimeGapRange, double baseAgressTimeGap, double lightChance, double heavyChance, double allOutChance);
	~AutomationComponent();


	//Updates
	void update(const float& dt, sf::Vector2f position);

	//getters
	Action* getCurrentAction() { return currentAction; };
	Agression* getCurrentAgression() { return currentAgression; };

};

