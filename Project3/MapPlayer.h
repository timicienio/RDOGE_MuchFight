#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include "Entity.h"

class MapPlayer
	: public Entity
{
public:
	MapPlayer(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~MapPlayer();

	void update(float deltaTime, sf::Keyboard::Key keyPressed, bool isPressed, bool canGo);
	void draw(sf::RenderTarget* window);

	sf::Vector2f getPosition() { return body.getPosition(); }
	Collider getCollider() { return Collider(body); }
	void searchDestinationCheckpoint(sf::Keyboard::Key keyPressed);
	bool move(sf::Keyboard::Key keyPressed, bool isPressed);

private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	sf::Vector2f destCheckpoint;
	bool judgeMove;
	bool havePressedEnter;
	bool canGo;
	sf::Keyboard::Key keyNeedToBe;
	sf::Vector2f* checkpoint[9];
};