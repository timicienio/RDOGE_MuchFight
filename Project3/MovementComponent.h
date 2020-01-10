#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

#include<vector>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<vector>
#include<stack>
#include<map>

#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"
#include"Animation.h"

#include"Variables.h"

class MovementComponent
{
private:
	sf::RectangleShape& body;
	float maxVelocity;
	float acceleration;
	float deceleration;
	float jumpHeight;

	bool canJump;

	sf::Vector2f velocity;
	//initializer functions


public:
	MovementComponent(sf::RectangleShape& body, float maxVelocity, float acceleration, float deceleration, float jumpHeight);
	~MovementComponent();

	//accessors
	sf::Vector2f& getVelocity();



	//functions

	void move(const float dir_x, const float dir_y, const float& dt, bool& canJump);
	void update(const float& dt);

	void playerJumpModification(const float dir_y, const float& dt, bool& canJump);

};

#endif
