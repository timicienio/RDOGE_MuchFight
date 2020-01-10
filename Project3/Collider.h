#pragma once
#include<SFML\Graphics.hpp>

class Collider
{
public:
	//constructor
	Collider(sf::RectangleShape& body);
	//a move function if the collider(the object checking for collision)
	void Move(float dx, float dy) { body.move(dx, dy); }
	//the function to check if the collider collides with the "other" object
	bool CheckCollision(Collider other, sf::Vector2f& direction, float push);
	//information for aabb collision detection
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.f; }
private:
	//the information of the collider
	sf::RectangleShape& body;
};

