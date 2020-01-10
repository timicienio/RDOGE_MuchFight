#pragma once

#include "Entity.h"
class Maisy : public Entity 
{

private:
	//variables


	//initializer functions
	void initVariables();
	void initComponents();

public:
	Maisy(float x, float y, sf::Texture& texture, float jumpHeight);
	virtual ~Maisy();

	//functions


	//getter for the enemy's position
sf::Vector2f getPosition() { return body.getPosition(); }

};

