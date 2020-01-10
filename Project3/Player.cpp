#include "Player.h"


//initializers
void Player::initVariables()
{
	body.setSize(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));
	body.setOrigin(sf::Vector2f(PLAYER_WIDTH / 2, PLAYER_HEIGHT / 2));
}

void Player::initComponents()
{
	this->createMovementComponent(300.f, 30.f, 10.f, jumpHeight);
	this->createCombatComponent(20, 1, 1, 4.f, 500.f, true);
}


//constructors/destructors
Player::Player(float x, float y, sf::Texture& texture , float jumpHeight) 
{
	x *= UNIT_LENGTH;
	y *= UNIT_LENGTH;

	this->jumpHeight = jumpHeight;
	this->initVariables();
	this->initComponents();
	this->setTexture(texture, sf::Vector2u(8, 3), 0.05f, IDLE_WIDTH, IDLE_HEIGHT, WALKING_WIDTH, WALKING_HEIGHT, JUMPING_WIDTH, JUMPING_HEIGHT);
	this->setPosition(x, y);

}

Player::~Player()
{
	delete this->movementComponent;
	delete this->combatComponent;
}

void Player::resetTimeSinceHurt()
{
	this->timeSinceHurt = 0.f;
}

void Player::updateStatus(const float& dt)
{
	this->timeSinceHurt += dt;
	this->currenDt = dt;

	if (this->timeSinceHurt > this->minHurtTimeGap)
	{
		this->canTakeDamage = true;
	}
}

void Player::render(sf::RenderTarget* target)
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

void Player::move(const float dir_x, const float dir_y, const float& dt, bool& canJump)
{
	if (this->movementComponent)
	{
		this->movementComponent->move(dir_x, dir_y, dt, canJump);//sets velocity
		this->movementComponent->playerJumpModification(dir_y, dt, canJump);
	}
}



