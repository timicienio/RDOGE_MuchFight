#include "AutomationComponent.h"

AutomationComponent::AutomationComponent(float idelTimeAvg, float idelTimeRange, float moveTimeAvg, float moveTimeRange, float leftChance, float jumpChance, float chaseChance, bool hasTreadIntention, float restTimeGapAvg, float restTimeGapRange, float agressTimeGapAvg, float agressTimeGapRange, float baseAgressTimeGap, float lightChance, float heavyChance, float allOutChance) 
{
	initVariables(idelTimeAvg, idelTimeRange, moveTimeAvg, moveTimeRange, leftChance, jumpChance, chaseChance, hasTreadIntention);
	initAgressionVariables(restTimeGapAvg, restTimeGapRange, agressTimeGapAvg, agressTimeGapRange, baseAgressTimeGap, lightChance, heavyChance, allOutChance
	
	);
	this->currentAction = new Action(idle, 0.1f, 0.2f, false);
	this->currentAgression = new Aggression(rest, 0.1f, 0.f);
}

void AutomationComponent::initVariables(float idelTimeAvg, float idelTimeRange, float moveTimeAvg, float moveTimeRange, float leftChance, float jumpChance, float chaseChance, bool hasTreadIntention)
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

void AutomationComponent::initAgressionVariables(float restTimeGapAvg, float restTimeGapRange, float agressTimeGapAvg, float agressTimeGapRange, float baseAgressTimeGap, float lightChance, float heavyChance, float allOutChance)
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
	float newTotalActionTime;
	float newJumpTime;


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
	float newTotalAgrssionTime;

	// determine next agression type and config

	float randNum = distribution(gen);
	float randNumNeg = distributionNeg(gen);

	float restChance = 1.f - this->lightChance - this->heavyChance - this->allOutChance;

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

	this->currentAgression = new Aggression(newStatus, newTotalAgrssionTime, this->baseAgressTimeGap);

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
