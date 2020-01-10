#pragma once
#include "Entity.h"
class Bicycle : public Entity 
{

private:
	//variables


	//initializer functions
	void initVariables();
	void initComponents();

public:
	Bicycle(float x, float y, sf::Texture& texture, float jumpHeight);
	virtual ~Bicycle();

	void update(const float& dt);

	//functions


	//getter for the enemy's position
	sf::Vector2f getPosition() { return body.getPosition(); }

};
