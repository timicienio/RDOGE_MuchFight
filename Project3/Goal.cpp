#include "Goal.h"

void Goal::initTexture(sf::Texture* texture)
{
	body.setTexture(texture);
}

Goal::Goal(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position) : animation(texture, sf::Vector2u(26,3), 0.01f, GOAL_IDLE_WIDTH, GOAL_IDLE_HEIGHT, GOAL_MOVING_WIDTH, GOAL_MOVING_HEIGHT, 0, 0)
{
	this->body.setSize(size);
	this->body.setPosition(position);
	initTexture(texture);
	this->playAnimation = false;
	this->animationRow = 2;
	this->switchTime = 0.01f;
}

void Goal::updateGoal(const float& dt, bool success)
{
	if (!(this->success) && success) {
		this->playAnimation = true;
		this->animationRow = 1;
		this->success = success;
	}
	if (this->playAnimation) {
		if (this->animation.playedOnce == true) {
			animation.setImageCount(sf::Vector2u(10, 3));
			playAnimation = false;
			animationRow = 0;
		}
		else{
			this->animation.update(animationRow, dt, true, 0.f, sf::Vector2f(0.f, 0.f));
			body.setTextureRect(animation.uvRect);
		}
	}
	else if(this->success){
		this->animation.update(animationRow, dt, true, 0.f, sf::Vector2f(0.f, 0.f));
		body.setTextureRect(animation.uvRect);
	}
	else {
		animation.uvRect.left = 0;
		animation.uvRect.top = GOAL_IDLE_HEIGHT + GOAL_MOVING_HEIGHT;
		animation.uvRect.width = GOAL_IDLE_WIDTH;
		animation.uvRect.height = GOAL_IDLE_HEIGHT;
		body.setTextureRect(animation.uvRect);
	}
}
