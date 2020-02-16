#pragma once

#include<vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"

#include "Animation.h"
#include "Animation.h"
#include "Collider.h"
#include "MovementComponent.h"



class CombatComponent {
 private:
     //// variables

     // if this component belongs to the player
     bool isPlayer;

     // maximum health
     int maxHealth;

     // remainig health
     int health;

     // 
     bool isAlive;

     // damage rate of attack, 0 if not available
     int nearAttackDamage;
     int farAttackDamage;

     // Cool Down time of attack type
     float farAttackCDTime;

     // time since the last attack
     float farAttackTimeGap;

     // range of far attack
     float farAttackRange;

     // within this distance, contact damage takes effect
     float contactRange;

 public:


     void initVariables(int maxHealth, int nearAttackDamage, int farAttackDamage, float farAttackCDTime, float farAttackRange, bool isPlayer);


     // Constructors/Destructors
     CombatComponent(int maxHealth, int nearAttackDamage, int farAttackDamage, float farAttackCDTime, float farAttackRange, bool isPlayer);

     ~CombatComponent();


  //Checkers
  //void onContact(Entity* thisEntity, Entity* otherEntity);

  // Updates
     void update();


  // Getters
     int getMaxHealth() { return maxHealth; };
     int getCurrentHeath() { return health; };

     int getNearAttack() { return nearAttackDamage; };
     int getFarAttack() { return farAttackDamage; };
     float getFarAttackRange() { return farAttackRange; };

     bool getIsAlive() { return isAlive; };
     bool getIsPlayer() { return isPlayer; };

  // Setters
     void takeDamage(int damage);
};
