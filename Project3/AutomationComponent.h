#pragma once

#include <random>
#include <iostream>

#include "Entities.h"

#include "Action.h"
#include "Aggression.h"

#include "Variables.h"

class AutomationComponent
{
private:
	//// Variables

	// Component References


	// Behavior Parameters

	// Action

	float idelTimeGapAvg;
	float idelTimeGapRange;

	float moveTimeGapAvg;
	float moveTimeGapRange;


	// The chance of the entity decide to move towards left when wandering
	float leftChance;
	// The chance of the entity decide to jump in every movement
	float jumpChance;
	// The chance of the entity chasing the player instead of wandering
	float chaseChance;

	// If this entity has the intention of treading the player
	bool hasTreadIntention;

	// Agression

	float restTimeGapAvg;
	float restTimeGapRange;

	float agressTimeGapAvg;
	float agressTimeGapRange;

	float baseAgressTimeGap;

	float lightChance;
	float heavyChance;
	float allOutChance;
	

	// Status
	EntityActionStatus actionStatus;
	
	Action* currentAction;
	Aggression* currentAgression;


	// Timers
	float timeSinceSpawn;

	// Random
	std::random_device rd;
	std::default_random_engine gen = std::default_random_engine(rd());

	std::uniform_real_distribution<float> distribution{ 0.0, 1.0 };
	std::uniform_real_distribution<float> distributionNeg{ -1.0, 1.0 };

	////Functions
	//Initializer
	void initVariables(float idelTimeAvg, float idelTimeRange, float moveTimeAvg, float moveTimeRange, float leftChance, float jumpChance, float chaseChance, bool hasTreadIntention);

	void initAgressionVariables(float restTimeGapAvg, float restTimeGapRange, float agressTimeGapAvg, float agressTimeGapRange, float baseAgressTimeGap, float lightChance, float heavyChance, float allOutChance);

	// Action
	void createAction();

	// Agression
	void createAgression();

public:
	//Constructor/Destructor
	AutomationComponent(float idelTimeAvg, float idelTimeRange, float moveTimeAvg, float moveTimeRange, float leftChance, float jumpChance, float chaseChance, bool hasTreadIntention, float restTimeGapAvg, float restTimeGapRange, float agressTimeGapAvg, float agressTimeGapRange, float baseAgressTimeGap, float lightChance, float heavyChance, float allOutChance);
	~AutomationComponent();


	//Updates
	void update(const float& dt, sf::Vector2f position);

	//getters
	Action* getCurrentAction() { return currentAction; };
	Aggression* getCurrentAgression() { return currentAgression; };

};

