#pragma once

//#include "GameState.h"
#include "Player.h"

class PlayerHealthBar
{
private:

	Player* player;
	std::vector<sf::RectangleShape> hearts;
	sf::Vector2f heartPosition;
	sf::Vector2f heartSize;
	float heartSpacing;
	sf::Texture* texture;
	void initHearts(int maxHealth);

public:

	//constructors/destructors
	PlayerHealthBar(Player* player, sf::Texture* texture);
	~PlayerHealthBar();
	void updatePosition(sf::Vector2f viewCenter);
	void render(sf::RenderTarget& target);

};

