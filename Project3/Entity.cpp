#include "Entity.h"

void Entity::initVariables()
{
	this->movementComponent = NULL;
	this->combatComponent = NULL;
	this->automationComponent = NULL;

	this->animationRow = 0;
	this->faceRight = false;
	this->canJump = true;
}

Entity::Entity() : body(sf::Vector2f(0.f, 0.f))
{
	this->initVariables();

	// components are initialized in child classes
}

Entity::~Entity()
{
	
}

//component functions
void Entity::setTexture(sf::Texture& texture, sf::Vector2u imageCount, float switchTime,
	unsigned int idleWidth,
	unsigned int idleHeight,
	unsigned int walkingWidth,
	unsigned int walkingHeight,
	unsigned int jumpingWidth,
	unsigned int jumpingHeight)
{
	this->body.setTexture(&texture);
	animation = new Animation(&texture, imageCount, switchTime, idleWidth, idleHeight, walkingWidth, walkingHeight, jumpingWidth, jumpingHeight);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration, float jumpHeight)
{
	
	this->movementComponent = new MovementComponent(this->body, maxVelocity, acceleration, deceleration, jumpHeight);

}

void Entity::createCombatComponent(int maxHealth, int nearAttackDamage, int farAttackDamage, float farAttackCDTime, float farAttackRange, bool isPlayer)
{

	this->combatComponent = new CombatComponent(maxHealth, nearAttackDamage, farAttackDamage, farAttackCDTime, farAttackRange, isPlayer);

}

void Entity::createAutomationComponent(float idelTimeAvg, float idelTimeRange, float moveTimeAvg, float moveTimeRange, float leftChance, float jumpChance, float chaseChance, bool hasTreadIntention, float restTimeGapAvg, float restTimeGapRange, float agressTimeGapAvg, float agressTimeGapRange, float baseAgressTimeGap, float lightChance, float heavyChance, float allOutChance)
{

	this->automationComponent = new AutomationComponent(idelTimeAvg, idelTimeRange, moveTimeAvg, moveTimeRange, leftChance, jumpChance, chaseChance, hasTreadIntention, restTimeGapAvg, restTimeGapRange, agressTimeGapAvg, agressTimeGapRange, baseAgressTimeGap, lightChance, heavyChance, allOutChance);

}



void Entity::setPosition(const float x, const float y)
{
	this->body.setPosition(x, y);

}

void Entity::move(const float dir_x, const float dir_y, const float& dt, bool& canJump)
{
	if (this->movementComponent)
	{
		this->movementComponent->move(dir_x, dir_y, dt, canJump); //sets velocity
	}
	
}

void Entity::update(const float& dt)
{
	if (this->combatComponent->getIsAlive()) // update only when alive
    {
		if (this->movementComponent) // update movement and textures
		{
			//std::cout << "move update" << "\n";
			this->movementComponent->update(dt);
			if (movementComponent->getVelocity().x == 0.f) {
				animationRow = 0;
			}
			else {
				animationRow = 1;
				if (movementComponent->getVelocity().x >= 0) {
					faceRight = true;
				}
				else {
					faceRight = false;
				}
			}
			float animationTime;
			if (canJump && movementComponent->getJumpedOnce() == false) {
				//deciding the speed of the animation
				if (animationRow == 0) {
					animationTime = dt * 0.2f;
				}
				else if (animationRow == 1) {
					//I want the walking animation to be faster
					animationTime = dt * 1.4f;
				}
			}
			else {
				animationRow = 2;
				animationTime = dt;
			}
			animation->update(animationRow, animationTime, faceRight, jumpHeight, movementComponent->getVelocity());
			body.setTextureRect(animation->uvRect);

		}

		this->combatComponent->update();

		if (!(this->combatComponent->getIsPlayer())) // not a player
		{
			this->automationComponent->update(dt, this->body.getPosition());

			// check canJump
			/*if (this->automationComponent->getCurrentAction()->getCurrentMovementOutput().y == -1.f)
			{
				this->canJump = false;
			}*/
		}
	}
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->body);
	
}

void Entity::resetTimeSinceHurt()
{
}

void Entity::onCollision(sf::Vector2f direction)
{
	if (direction.x > 0) {
		movementComponent->velocity.x = 0;
	}
	if (direction.x < 0) {
		movementComponent->velocity.x = 0;
	}
	if (direction.y < 0) {
		movementComponent->velocity.y = 0;
		canJump = true;
		movementComponent->resetDoubleJump();
	}
	if (direction.y > 0) {
		movementComponent->velocity.y = 0;
	}
}

void Entity::playerOnEnemyCollision(sf::Vector2f direction)
{
	if (direction.x > 0) {
		movementComponent->velocity.x = direction.x * 0.6f * KNOCKBACK_VELOCITY;
	}
	if (direction.x < 0) {
		movementComponent->velocity.x = direction.x * 0.6f * KNOCKBACK_VELOCITY;
	}
	if (direction.y < 0) {
		movementComponent->velocity.y = direction.y * 0.6f * KNOCKBACK_VELOCITY_VERTICAL;
		canJump = true;
		movementComponent->resetDoubleJump();
	}
	if (direction.y > 0) {
		movementComponent->velocity.y = direction.y * 0.6f * KNOCKBACK_VELOCITY_VERTICAL;
	}
}
