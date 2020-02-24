#pragma once

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
	bool jumpedOnce;

	sf::Vector2f velocity;
	//initializer functions


public:
	MovementComponent(sf::RectangleShape& body, float maxVelocity, float acceleration, float deceleration, float jumpHeight);
	~MovementComponent();

	//accessors
	const sf::Vector2f& getVelocity()const;



	//functions

	void move(const float dir_x, const float dir_y, const float& dt, bool& canJump);
	void update(const float& dt);

	void resetDoubleJump();
	const bool& getJumpedOnce() { return this->jumpedOnce; };

	void playerJumpModification(const float dir_y, const float& dt, bool& canJump);

	friend class Entity;
};
