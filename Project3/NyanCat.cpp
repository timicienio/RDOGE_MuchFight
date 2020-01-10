#include "NyanCat.h"

void NyanCat::initVariables()
{
	body.setSize(sf::Vector2f(NYANCAT_WIDTH, NYANCAT_HEIGHT));
	body.setOrigin(sf::Vector2f(NYANCAT_WIDTH / 2, NYANCAT_HEIGHT / 2));
}

void NyanCat::initComponents()
{
	this->createMovementComponent(100.f, 20.f, 5.f, this->jumpHeight);
	this->createCombatComponent(2, 1, 1, -1.f, 8.f * UNIT_LENGTH, false);
	this->createAutomationComponent(0.1f, 0.02f, 2.f, 0.3f, 0.5f, 0.2f, 0.3f, true, 2.f, 0.5f, 12.f, 2.f, 1.5f, 0.3f, 0.25f, 0.1f);
}


//constructors/destructors
NyanCat::NyanCat(float x, float y, sf::Texture& texture , float jumpHeight) 
{
	x *= UNIT_LENGTH;
	y *= UNIT_LENGTH;

	this->jumpHeight = jumpHeight;
	this->initVariables();
	this->initComponents();
	this->setTexture(texture, sf::Vector2u(12, 1), 0.05f, NYANCAT_IDLE_WIDTH, NYANCAT_IDLE_HEIGHT, 0, 0, 0, 0);
	this->setPosition(x, y);

}

NyanCat::~NyanCat()
{
	delete this->movementComponent;
	delete this->combatComponent;
	delete this->automationComponent;
}

void NyanCat::render(sf::RenderTarget* target)
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

void NyanCat::resetTimeSinceHurt()
{
	this->timeSinceHurt = 0.f;
}

void NyanCat::updateStatus(const float& dt)
{
	this->timeSinceHurt += dt;
	this->currenDt = dt;

	if (this->timeSinceHurt > this->minHurtTimeGap)
	{
		this->canTakeDamage = true;
	}
}

void NyanCat::update(const float& dt)
{
	if (this->combatComponent->getIsAlive()) // update only when alive
	{
		if (this->movementComponent) // update movement and textures
		{
			//std::cout << "move update" << "\n";
			this->movementComponent->update(dt);
			if (movementComponent->getVelocity().x >= 0) {
				faceRight = true;
			}
			else {
				faceRight = false;
			}
			unsigned int animationRow = 0;
			animation->update(animationRow, dt, faceRight, jumpHeight, movementComponent->getVelocity());
			body.setTextureRect(animation->uvRect);

		}

		this->combatComponent->update();

		this->automationComponent->update(dt, this->body.getPosition());

	}
}