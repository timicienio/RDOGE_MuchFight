#include "AutomationComponent.h"

AutomationComponent::AutomationComponent(double idelTimeAvg, double idelTimeRange, double moveTimeAvg, double moveTimeRange, double leftChance, double jumpChance, double chaseChance, bool hasTreadIntention, double restTimeGapAvg, double restTimeGapRange, double agressTimeGapAvg, double agressTimeGapRange, double baseAgressTimeGap, double lightChance, double heavyChance, double allOutChance) 
{
	initVariables(idelTimeAvg, idelTimeRange, moveTimeAvg, moveTimeRange, leftChance, jumpChance, chaseChance, hasTreadIntention);
	initAgressionVariables(restTimeGapAvg, restTimeGapRange, agressTimeGapAvg, agressTimeGapRange, baseAgressTimeGap, lightChance, heavyChance, allOutChance
	
	);
	this->currentAction = new Action(idle, 0.1f, 0.2f, false);
	this->currentAgression = new Agression(rest, 0.1f, 0.f);
}

void AutomationComponent::initVariables(double idelTimeAvg, double idelTimeRange, double moveTimeAvg, double moveTimeRange, double leftChance, double jumpChance, double chaseChance, bool hasTreadIntention)
{
	this->idelTimeGapAvg = idelTimeAvg;
	this->idelTimeGapRange = idelTimeRange;
	this->moveTimeGapAvg = moveTimeAvg;
	this->moveTimeGapRange = moveTimeRange;

	this->leftChance = leftChance;
	this->jumpChance = jumpChance;
	this->chaseChance = chaseChance;

	this->hasTreadIntention = hasTreadIntention;
}

void AutomationComponent::initAgressionVariables(double restTimeGapAvg, double restTimeGapRange, double agressTimeGapAvg, double agressTimeGapRange, double baseAgressTimeGap, double lightChance, double heavyChance, double allOutChance)
{
	this->restTimeGapAvg = restTimeGapAvg;
	this->restTimeGapRange = restTimeGapRange;
	this->agressTimeGapAvg = agressTimeGapAvg;
	this->agressTimeGapRange = agressTimeGapRange;

	this->baseAgressTimeGap = baseAgressTimeGap;

	this->lightChance = lightChance;
	this->heavyChance = heavyChance;
	this->allOutChance = allOutChance;
}

void AutomationComponent::createAction()
{
	EntityActionStatus newStatus;
	double newTotalActionTime;
	double newJumpTime;


	// decide type of the next action
	// alternate between move and idle
	if (this->currentAction->getType() == idle)
	{
		if (distribution(gen) <= this->chaseChance)
		{
			newStatus = chasing;
		}
		else
		{
			if (distribution(gen) <= this->leftChance)
			{
				newStatus = wanderingLeft;
			}
			else
			{
				newStatus = wanderingRight;
			}

		}

		newTotalActionTime = moveTimeGapAvg + moveTimeGapRange * distributionNeg(gen);

		if (distribution(gen) <= this->jumpChance)
		{
			newJumpTime = newTotalActionTime * distribution(gen);
		}
		else
		{
			newJumpTime = newTotalActionTime + 1; // don't jump
		}
	}

	else
	{
		newStatus = idle;
		newTotalActionTime = idelTimeGapAvg + idelTimeGapRange * distributionNeg(gen);
		newJumpTime = newTotalActionTime + 1;
	}

	//std::cout << "action changed" << std::endl;
	//std::cout << newStatus  << " " << newTotalActionTime << " " << newJumpTime << std::endl;
	delete this->currentAction;

	this->currentAction = new Action(newStatus, newTotalActionTime, newJumpTime, this->hasTreadIntention);
}

void AutomationComponent::createAgression()
{
	EntityAgressionStatus newStatus;
	double newTotalAgrssionTime;

	// determine next agression type and config

	double randNum = distribution(gen);
	double randNumNeg = distributionNeg(gen);

	double restChance = 1.f - this->lightChance - this->heavyChance - this->allOutChance;

	if (randNum < restChance) // rest
	{
		newStatus = rest;

		newTotalAgrssionTime = this->restTimeGapAvg + this->restTimeGapRange * randNumNeg;
	}
	else if (randNum >= restChance + this->lightChance && randNum < restChance + this->lightChance + this->heavyChance) // light
	{
		newStatus = light;

		newTotalAgrssionTime = this->agressTimeGapAvg + this->agressTimeGapRange * randNumNeg;
	}
	else if (randNum >= restChance + this->lightChance + this->heavyChance && randNum < restChance + this->lightChance + this->heavyChance + this->allOutChance) // heavy
	{
		newStatus = heavy;

		newTotalAgrssionTime = this->agressTimeGapAvg + this->agressTimeGapRange * randNumNeg;
	}
	else // all out
	{
		newStatus = allOut;

		newTotalAgrssionTime = this->agressTimeGapAvg + this->agressTimeGapRange * randNumNeg;
	}

	delete this->currentAgression;

	this->currentAgression = new Agression(newStatus, newTotalAgrssionTime, this->baseAgressTimeGap);

}

AutomationComponent::~AutomationComponent()
{
    delete this->currentAction;
	delete this->currentAgression;
}

void AutomationComponent::update(const float& dt, sf::Vector2f position)
{
	if (this->currentAction->hasEnded) // switch to next action
	{
		this->createAction(); 
		//std::cout << "created action" << std::endl;
	}
	else // continue current action
	{
		this->currentAction->update(dt, position);
	}	

	if (this->currentAgression->hasEnded) // switch to next agression
	{
		this->createAgression();
	}
	else // continue current agression
	{
		this->currentAgression->update(dt, this->currentAction->getCurrentMovementOutput(), position);
	}
}
