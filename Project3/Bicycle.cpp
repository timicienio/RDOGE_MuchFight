#include "Bicycle.h"


//initializers
void Bicycle::initVariables()
{
	body.setSize(sf::Vector2f(BICYCLE_WIDTH, BICYCLE_HEIGHT));
	body.setOrigin(sf::Vector2f(BICYCLE_WIDTH / 2, BICYCLE_HEIGHT / 2));
}

void Bicycle::initComponents()
{
	this->createMovementComponent(600.f, 60.f, 10.f, this->jumpHeight);
	this->createCombatComponent(1, 1, 1, 4.f, 500.f, false);
	this->createAutomationComponent(0.f, 0.f, 3600.f, 0.f, 1.f, 0.f, 0.f, false, 3600.f, 0.f, 0.f, 0.f, 3600.f, 0.f, 0.f, 0.f);
}


//constructors/destructors
Bicycle::Bicycle(float x, float y, sf::Texture& texture , float jumpHeight) 
{
	x *= UNIT_LENGTH;
	y *= UNIT_LENGTH;

	this->jumpHeight = jumpHeight;
	this->initVariables();
	this->initComponents();
	this->setTexture(texture, sf::Vector2u(6,1), 0.05f, BIKE_IDLE_WIDTH, BIKE_IDLE_HEIGHT, 0, 0, 0, 0);
	this->setPosition(x, y);

}

Bicycle::~Bicycle()
{
	delete this->movementComponent;
	delete this->combatComponent;
	delete this->automationComponent;
}

void Bicycle::update(const float& dt)
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