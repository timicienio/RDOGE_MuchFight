#pragma once
#include "Entity.h"


class Player :
	public Entity
{
private:
	////variables

	//status

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

	//variables
	// score
	int score = 0;

	//if the player can take damage
	

	//constructors/destructors
	Player(float x, float y, sf::Texture& texture, float jumpHeight);
	virtual ~Player();

	////functions

	//getter for the player's position
	sf::Vector2f getPosition() { return body.getPosition(); }

	//setters
	void resetTimeSinceHurt();

	//void update(const float& dt);

	void updateStatus(const float& dt);

	void render(sf::RenderTarget* target);

	void move(const float dir_x, const float dir_y, const float& dt, bool& canJump);
	

};

