#pragma once

#include "Entity.h"
class WickedDoge : public Entity 
{

private:
	//variables

	// status
	//time since the last time the entity took damage
	double timeSinceHurt = 0.f;
	//minimum time between taking damage
	double minHurtTimeGap = 2.f;


	//initializer functions
	void initVariables();
	void initComponents();

	// implement flicker
	const double flickerTimeGap = 0.1f;
	double currentFlickerTime = 0.f;
	bool flickerNoRender;

	float currenDt = 0.f;

public:
	WickedDoge(float x, float y, sf::Texture& texture, float jumpHeight);
	virtual ~WickedDoge();

	void render(sf::RenderTarget* target);

	//functions
	void resetTimeSinceHurt();

	//getter for the enemy's position
	sf::Vector2f getPosition() { return body.getPosition(); }

	void updateStatus(const float& dt);
};

