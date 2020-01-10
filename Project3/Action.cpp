#include "Action.h"

Action::Action(EntityActionStatus typeOfAction, double totalActionTime, double jumpTime, bool hasTreadIntention)
{
	this->typeOfAction = typeOfAction;
	this->totalActionTime = totalActionTime;
	this->jumpTime = jumpTime;
	this->hasTreadIntention = hasTreadIntention;
}

Action::~Action()
{
}

void Action::update(const float& dt, sf::Vector2f position)
{
	this->currentActionTime += dt;
	this->currentRestTime += dt;
	this->currentMovementOutput.x = 0.f;
	this->currentMovementOutput.y = 0.f;

	if (currentActionTime > totalActionTime)
	{
		hasEnded = true;
	}

	else
	{
		switch (this->typeOfAction)
		{
		case idle:
			// does nothing
			break;

		case wanderingLeft:

			if (this->currentActionTime > this->jumpTime)
			{
				this->currentMovementOutput.y = -1.f; //jump
				jumpTime = totalActionTime + 1; // don't jump again
			}
			else
			{
				this->currentMovementOutput.x = -0.55f;
			}

			break;

		case wanderingRight:

			if (this->currentActionTime > this->jumpTime)
			{
				this->currentMovementOutput.y = -1.f; //jump
				this->jumpTime = totalActionTime + 1; // don't jump again
			}
			else
			{
				this->currentMovementOutput.x = 0.55f;
			}

			break;

		case chasing:

			if (this->currentActionTime > this->jumpTime) //random jump
			{
				this->currentRestTime = 0;
				
				this->currentMovementOutput.y = -1.f; //jump
				this->jumpTime = totalActionTime + 1; // don't jump again
			}

			else if (position.x > this->currentChaseTargetPosition.x - 5.f && position.x < this->currentChaseTargetPosition.x + 5.f) // near the center of player
			{
				if (this->currentRestTime > this->treadRestTime)
				{
					this->currentRestTime = 0;

					this->currentMovementOutput.y = -1.f; //jump
				}
			}

			else if (position.x < this->currentChaseTargetPosition.x) // target is on the right
			{
				if (this->hasTreadIntention && (position.x >= this->currentChaseTargetPosition.x - 200) && (this->currentRestTime > this->treadRestTime)) // try tread
				{
					this->currentRestTime = 0;

					this->currentMovementOutput.y = -1.f; //jump
				}
				else
				{
					this->currentMovementOutput.x = 1.f;
				}
			}

			else // target is on the left
			{
				if ((this->hasTreadIntention && (position.x <= this->currentChaseTargetPosition.x + 200)) && (this->currentRestTime > this->treadRestTime)) // try tread
				{
					this->currentRestTime = 0;

					this->currentMovementOutput.y = -1.f; //jump
				}
				else
				{
					this->currentMovementOutput.x = -1.f;
				}
			}

			break;

		default:
			break;
		}
	}


}

void Action::setChaseTargetPosition(sf::Vector2f coordinate)
{
	this->currentChaseTargetPosition = coordinate;

	// modify to center
	this->currentChaseTargetPosition.x += 25.f;
	this->currentChaseTargetPosition.y += 25.f;
}