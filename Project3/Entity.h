#ifndef ENTITY_H
#define ENTITY_H


#include "CombatComponent.h"
#include "AutomationComponent.h"


class Entity
{
private:
	void initVariables();

protected:

	Animation* animation;
	unsigned int animationRow;

	// components
	sf::RectangleShape body;
	MovementComponent* movementComponent;
	CombatComponent* combatComponent;
	AutomationComponent* automationComponent;

	bool faceRight;


	float jumpHeight;

public:

	// if the entity can take damage
	bool canTakeDamage = true;

	Entity();
	virtual ~Entity();

	// component functions
	void setTexture(sf::Texture& texture, sf::Vector2u imageCount, float switchTime,
		unsigned int idleWidth,
		unsigned int idleHeight,
		unsigned int walkingWidth,
		unsigned int walkingHeight,
		unsigned int jumpingWidth,
		unsigned int jumpingHeight);
	void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration, float jumpHeight);
	void createCombatComponent(int maxHealth, int nearAttackDamage, int farAttackDamage, float farAttackCDTime, float farAttackRange, bool isPlayer);
	void createAutomationComponent(float idelTimeAvg, float idelTimeRange, float moveTimeAvg, float moveTimeRange, float leftChance, float jumpChance, float chaseChance, bool hasTreadIntention, float restTimeGapAvg, float restTimeGapRange, float agressTimeGapAvg, float agressTimeGapRange, float baseAgressTimeGap, float lightChance, float heavyChance, float allOutChance);

	// updating functions
	virtual void setPosition(const float x, const float y);
	virtual void move(const float dir_x, const float dir_y, const float& dt, bool& canJump);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);

	virtual void resetTimeSinceHurt();


	// component getters
	Collider getCollider() { return Collider(body); }






	MovementComponent* getMovementComponent() { return movementComponent; };
	CombatComponent* getCombatComponent() { return combatComponent; };
	AutomationComponent* getAutomationComponent() { return automationComponent; };
	void onCollision(sf::Vector2f direction);
	void playerOnEnemyCollision(sf::Vector2f direction);
	
	bool canJump;
};

#endif
