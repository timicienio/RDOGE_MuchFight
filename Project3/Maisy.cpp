#include "Maisy.h"

//initializers
void Maisy::initVariables()
{
	body.setSize(sf::Vector2f(MAISY_WIDTH, MAISY_HEIGHT));
	body.setOrigin(sf::Vector2f(MAISY_WIDTH / 2, MAISY_HEIGHT / 2));
}

void Maisy::initComponents()
{
	this->createMovementComponent(160.f, 20.f, 3.f, this->jumpHeight);
	this->createCombatComponent(1, 1, 1, 4.f, 500.f, false);
	this->createAutomationComponent(0.6, 0.3, 5.f, 2.f, 0.5, 0.3, 0.7, true, 3600.f, 0.f, 0.f, 0.f, 3600.f, 0.f, 0.f, 0.f);
}


//constructors/destructors
Maisy::Maisy(float x, float y, sf::Texture& texture , float jumpHeight) 
{
	x *= UNIT_LENGTH;
	y *= UNIT_LENGTH;

	this->jumpHeight = jumpHeight;
	this->initVariables();
	this->initComponents();
	this->setTexture(texture, sf::Vector2u(5,3), 0.05f, MAISY_IDLE_WIDTH, MAISY_IDLE_HEIGHT, MAISY_WALKING_WIDTH, MAISY_WALKING_HEIGHT, MAISY_JUMPING_WIDTH, MAISY_JUMPING_HEIGHT);
	this->setPosition(x, y);

}

Maisy::~Maisy()
{
	delete this->movementComponent;
	delete this->combatComponent;
	delete this->automationComponent;
}