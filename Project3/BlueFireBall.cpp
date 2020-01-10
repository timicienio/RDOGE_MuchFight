#include "BlueFireBall.h"

void BlueFireBall::initVariables(sf::Vector2f position, sf::Vector2f size, sf::Vector2f velocity, int damage, double range)
{
	this->position = position;
	this->velocity = velocity;
	this->damage = damage;
	this->range = range;

	// change to real velocity
	this->velocity.x *= this->baseVelocity;

	// initialize body
	body.setSize(size);
	body.setOrigin(size / 2.f);
	body.setPosition(position);
}

void BlueFireBall::initAnimation(sf::Texture& texture)
{
	this->animation = new Animation(&texture, sf::Vector2u(9, 1), 0.1f, FIREBALL_WIDTH, FIREBALL_HEIGHT, 0, 0, 0, 0);
}

void BlueFireBall::move(const float& dt)
{
	this->currentTravelDistance += std::fabs(this->velocity.x * dt);
	this->body.move(this->velocity * dt);
}

BlueFireBall::BlueFireBall(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, sf::Vector2f velocity, int damage, double range)
{
	this->initVariables(position, size, velocity, damage, range);
	this->initAnimation(*texture);
	if (texture == nullptr) {
		body.setFillColor(sf::Color(0, 0, 255, 100));
	}
	body.setTexture(texture);
	if (this->velocity.x < 0.f) {
		faceRight = false;
	}
	else {
		faceRight = true;
	}
	
	
}

BlueFireBall::~BlueFireBall()
{
	//delete this->animation;
}

void BlueFireBall::render(sf::RenderTarget* target)
{
	target->draw(body);
}

bool BlueFireBall::outOfRange()
{
	if (this->currentTravelDistance > this->range)
	{
		return true;
	}
	return false;
}

void BlueFireBall::update(const float& dt)
{
	this->move(dt);
	animation->update(0, dt, this->faceRight, 0,this-> velocity);
	this->body.setTextureRect(this->animation->uvRect);
}
