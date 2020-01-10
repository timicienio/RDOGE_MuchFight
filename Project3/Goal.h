#pragma once
#include"SFML\Graphics.hpp"
#include"Animation.h"

class Goal
{
private:
	sf::RectangleShape body;
	sf::Texture* texture;
	Animation animation;
	bool success;
	bool playAnimation;
	unsigned int animationRow;
	float switchTime;
private:
	void initTexture(sf::Texture* texture);

public:
	Goal(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	void updateGoal(const float& dt, bool success);
	void render(sf::RenderTarget* target) { target->draw(body); }
};

