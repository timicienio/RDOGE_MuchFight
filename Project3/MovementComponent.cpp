#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::RectangleShape& body,
	float maxVelocity, float acceleration, float deceleration, float jumpHeight)
	: body(body), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration), jumpHeight(jumpHeight), canJump(false)
{
}

MovementComponent::~MovementComponent()
{
	//delete this->body;

}

sf::Vector2f& MovementComponent::getVelocity()
{
	return this->velocity;
}

void MovementComponent::move(const float dir_x, const float dir_y, const float& dt, bool& canJump)
{
	if (velocity.y != 0.f) {
		canJump = false;
	}
	if (dir_y < 0 && canJump) {
		velocity.y = -sqrt(2 * GRAVITY * jumpHeight);
	}
	//acceleration
	if(canJump){
		this->velocity.x += this->acceleration * dir_x;
	}
	else {
		this->velocity.x += this->acceleration / 2.f * dir_x;
	}
	this->canJump = canJump;
}

void MovementComponent::update(const float& dt)
{
	//deceleration
	if (this->canJump) {
		if (this->velocity.x > 0.f)
		{
			if (this->velocity.x > this->maxVelocity)
				this->velocity.x = this->maxVelocity;

			this->velocity.x -= deceleration;
			if (this->velocity.x < 0.f)
				velocity.x = 0.f;
		}
		else if (this->velocity.x < 0.f)
		{
			if (this->velocity.x < -this->maxVelocity)
				this->velocity.x = -this->maxVelocity;

			this->velocity.x += deceleration;
			if (this->velocity.x > 0.f)
				velocity.x = 0.f;
		}
	}
	else {
		if (this->velocity.x > 0.f)
		{
			if (this->velocity.x > this->maxVelocity)
				this->velocity.x = this->maxVelocity;

			this->velocity.x -= deceleration / 1.5f;
			if (this->velocity.x < 0.f)
				velocity.x = 0.f;
		}
		else if (this->velocity.x < 0.f)
		{
			if (this->velocity.x < -this->maxVelocity)
				this->velocity.x = -this->maxVelocity;

			this->velocity.x += deceleration / 1.5f;
			if (this->velocity.x > 0.f)
				velocity.x = 0.f;
		}
	}


	this->velocity.y += GRAVITY * dt;
	if (velocity.y > MAX_DROP_SPEED) {
		velocity.y = MAX_DROP_SPEED;
	}
	//final move
	//std::cout << "move" << "\n";
	this->body.move(this->velocity * dt); //use velocity
}

void MovementComponent::playerJumpModification(const float dir_y, const float& dt, bool& canJump)
{
	if ((!canJump) && velocity.y < 0 && dir_y == 0) {
		velocity.y *= 0.9f * (1.f - dt);
	}
}