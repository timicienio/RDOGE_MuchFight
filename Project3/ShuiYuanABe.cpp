#include "ShuiYuanABe.h"



//initializers
void ShuiYuanABe::initVariables()
{
	body.setSize(sf::Vector2f(SHUIYUANABE_WIDTH, SHUIYUANABE_HEIGHT));
	body.setOrigin(sf::Vector2f(SHUIYUANABE_WIDTH / 2, SHUIYUANABE_HEIGHT / 2));
}

void ShuiYuanABe::initComponents()
{
	this->createMovementComponent(100.f, 20.f, 5.f, this->jumpHeight);
	this->createCombatComponent(3, 2, 1, -1.f, 15.f * UNIT_LENGTH, false);
	this->createAutomationComponent(1.5f, 0.2f, 3.f, 1.f, 0.5f, 0.7f, 0.25f, true, 4.f, 1.f, 6.f, 1.f, 1.f, 0.3f, 0.2f, 0.05f);
}


//constructors/destructors
ShuiYuanABe::ShuiYuanABe(float x, float y, sf::Texture& texture , float jumpHeight) 
{
	x *= UNIT_LENGTH;
	y *= UNIT_LENGTH;

	this->jumpHeight = jumpHeight;
	this->initVariables();
	this->initComponents();
	this->setTexture(texture, sf::Vector2u(14, 3), 0.05f, SHUIYUANABE_IDLE_WIDTH, SHUIYUANABE_IDLE_HEIGHT, SHUIYUANABE_WALKING_WIDTH, SHUIYUANABE_WALKING_HEIGHT, SHUIYUANABE_JUMPING_WIDTH, SHUIYUANABE_JUMPING_HEIGHT);
	this->setPosition(x, y);

}

ShuiYuanABe::~ShuiYuanABe()
{
	delete this->movementComponent;
	delete this->combatComponent;
	delete this->automationComponent;
}

void ShuiYuanABe::render(sf::RenderTarget* target)
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

void ShuiYuanABe::resetTimeSinceHurt()
{
	this->timeSinceHurt = 0.f;
}

void ShuiYuanABe::updateStatus(const float& dt)
{
	this->timeSinceHurt += dt;
	this->currenDt = dt;

	if (this->timeSinceHurt > this->minHurtTimeGap)
	{
		this->canTakeDamage = true;
	}
}