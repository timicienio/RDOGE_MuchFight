#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"
#include "Variables.h"
#include "Animation.h"
#include <iostream>
#include <stdlib.h>

// harmful for player

class BlueFireBall
{
private:

	// initializer
	void initVariables(sf::Vector2f position, sf::Vector2f size, sf::Vector2f velocity, int damage, float range);
	void initAnimation(sf::Texture& texture);

	// movement informations & states

	const float baseVelocity = 7.5f * UNIT_LENGTH;

	sf::Vector2f velocity;
	sf::Vector2f position;


	float range;
	float currentTravelDistance = 0.f;


	// damage information
	int damage;

	// mover
	void move(const float& dt);

	Animation* animation;
	unsigned int animationRow;

	//the physical object
	sf::RectangleShape body;

	bool faceRight;

public:

	//constructor
	BlueFireBall(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, sf::Vector2f velocity, int damage, float range);
	~BlueFireBall();

	//a draw function for the object
	void render(sf::RenderTarget* target);

	//getter for class collider object
	Collider getCollider() { return Collider(body); }

	sf::Vector2f getPosition() { return body.getPosition(); }
	sf::Vector2f getVelocity() { return velocity; };

	// getter of damage amount
	int getDamage() { return damage; };

	// getter 
	bool outOfRange();

	void update(const float& dt);



};

