#include "CombatComponent.h"


CombatComponent::CombatComponent(int maxHealth, int nearAttackDamage, int farAttackDamage, double farAttackCDTime, double farAttackRange, bool isPlayer) {

	this->initVariables(maxHealth, nearAttackDamage, farAttackDamage, farAttackCDTime, farAttackRange, isPlayer);
}


CombatComponent::~CombatComponent() {}




void CombatComponent::update()
{
    if (this->health <= 0)
    {
        isAlive = false;
    }
}


void CombatComponent::takeDamage(int damage)
{
    this->health -= damage;
}

void CombatComponent::initVariables(int maxHealth, int nearAttackDamage,
                                    int farAttackDamage, double farAttackCDTime,
                                    double farAttackRange, bool isPlayer) 
{

    this->maxHealth = maxHealth;
    this->health = maxHealth;
    this->nearAttackDamage = nearAttackDamage;
    this->farAttackDamage = farAttackDamage;
    this->farAttackCDTime = farAttackDamage;
    this->farAttackRange = farAttackRange;
    this->isPlayer = isPlayer;

    this->isAlive = true;
}

