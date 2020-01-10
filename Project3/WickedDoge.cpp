#include "WickedDoge.h"

//initializers
void WickedDoge::initVariables()
{
	body.setSize(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));
	body.setOrigin(sf::Vector2f(PLAYER_WIDTH / 2, PLAYER_HEIGHT / 2));
}

void WickedDoge::initComponents()
{
	this->createMovementComponent(200.f, 30.f, 10.f, this->jumpHeight);
	this->createCombatComponent(2, 1, 1, -1.f, 3600.f, false);
	this->createAutomationComponent(1.5f, 0.3, 5.f, 2.f, 0.5, 0.9, 0.3, false, 3600.f, 0.f, 0.f, 0.f, 3600.f, 0.f, 0.f, 0.f);
}


//constructors/destructors
WickedDoge::WickedDoge(float x, float y, sf::Texture& texture , float jumpHeight) 
{
	x *= UNIT_LENGTH;
	y *= UNIT_LENGTH;

	this->jumpHeight = jumpHeight;
	this->initVariables();
	this->initComponents();
	this->setTexture(texture, sf::Vector2u(5,3), 0.05f, IDLE_WIDTH, IDLE_HEIGHT, WALKING_WIDTH, WALKING_HEIGHT, JUMPING_WIDTH, JUMPING_HEIGHT);
	this->setPosition(x, y);

}

WickedDoge::~WickedDoge()
{
	delete this->movementComponent;
	delete this->combatComponent;
	delete this->automationComponent;
}

void WickedDoge::render(sf::RenderTarget* target)
{
	if (!canTakeDamage) // flicker
	{
		currentFlickerTime += this->currenDt;
		if (currentFlickerTime > flickerTimeGap)
		{
			flickerNoRender = !flickerNoRender;
			currentFlickerTime = 0.f;
		}
		if (!flickerNoRender)
		{
			target->draw(this->body);
		}
	}
	else
	{
		target->draw(this->body);
	}
}

void WickedDoge::resetTimeSinceHurt()
{
	this->timeSinceHurt = 0.f;
}

void WickedDoge::updateStatus(const float& dt)
{
	this->timeSinceHurt += dt;
	this->currenDt = dt;

	if (this->timeSinceHurt > this->minHurtTimeGap)
	{
		this->canTakeDamage = true;
	}
}