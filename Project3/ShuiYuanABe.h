#pragma once
#include "Entity.h"
class ShuiYuanABe :
	public Entity
{

private:
	//variables

	// status
	//time since the last time the entity took damage
	double timeSinceHurt = 0.f;
	//minimum time between taking damage
	double minHurtTimeGap = 3.f;


	//initializer functions
	void initVariables();
	void initComponents();

	// implement flicker
	const double flickerTimeGap = 0.1f;
	double currentFlickerTime = 0.f;
	bool flickerNoRender;

	float currenDt = 0.f;

public:

	ShuiYuanABe(float x, float y, sf::Texture& texture, float jumpHeight);
	virtual ~ShuiYuanABe();

	//functions


	//getter for the enemy's position
	sf::Vector2f getPosition() { return body.getPosition(); }


	void render(sf::RenderTarget* target);

	void resetTimeSinceHurt();

	//void update(const float& dt);

	void updateStatus(const float& dt);
};

