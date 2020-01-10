#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"
#include "Variables.h"
#include <iostream>

class Platform
{
public:
	//constructor
	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	//a draw function for the platform
	void render(sf::RenderTarget* target);
	//getter for class collider platform
	Collider getCollider() { return Collider(body); }
	sf::Vector2f getPosition() { return body.getPosition(); }
private:
	//the platform
	sf::RectangleShape body;
};

