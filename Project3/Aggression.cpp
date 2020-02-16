#include "Aggression.h"

Aggression::Aggression(EntityAgressionStatus typeOfAgression, float totalAgressionTime, float baseAgressTimeGap)
{
	this->typeOfAgression = typeOfAgression;
	this->totalAgressionTime = totalAgressionTime;
	this->baseAgressTimeGap = baseAgressTimeGap;
}

Aggression::~Aggression()
{

}

void Aggression::update(const float& dt, sf::Vector2f currentMovementOutput, sf::Vector2f position)
{
	this->currentAgressionTime += dt;
	this->currenRestTime += dt;
	this->currentAgressOutput.x = 0.f;
	this->currentAgressOutput.y = 0.f;

	if (this->currentAgressionTime > totalAgressionTime)
	{
		hasEnded = true;
	}
	
	else
	{
		switch (this->typeOfAgression)
		{
		case rest:
			// does nothing
			break;

		case light:
			
			if (this->currenRestTime > this->baseAgressTimeGap * 2.f)
			{
				this->currentAgressOutput.x = currentMovementOutput.x * 0.8f; // this will produce weaker fireballs, arrows, etc.
				this->currenRestTime = 0.f;
			}

			break;

		case heavy:

			if (this->currenRestTime > this->baseAgressTimeGap * 1.f)
			{
				this->currentAgressOutput.x = currentMovementOutput.x * 1.f;
				this->currenRestTime = 0.f;
			}

			break;

		case allOut:

			if (this->currenRestTime > this->baseAgressTimeGap * 0.3f)
			{
				this->currentAgressOutput.x = currentMovementOutput.x * 1.2f; // this will produce stronger fireballs, arrows, etc.
				this->currenRestTime = 0.f;
			}

		default:
			break;
		}

	}
}
