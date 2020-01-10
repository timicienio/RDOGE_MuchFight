#pragma once


#include<vector>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<vector>
#include<stack>
#include<map>


#include "Button.h"
#include "Player.h"

#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"


class GameoverState
{
private:
	sf::Font& font;
	sf::Text menuText;
	sf::View view;
	sf::RectangleShape background;
	sf::RectangleShape container;
	//sf::RectangleShape scoreContainer;
	std::map<std::string, Button*> buttons;

	Player* player;

	//private functions


public:
	GameoverState(sf::RenderWindow& window, sf::Font& font, Player* player);
	virtual ~GameoverState();

	sf::Text score;
	//accessor
	std::map<std::string, Button*>& getButtons();


	//functions
	//	const bool isButtonPressed(const std::string key);
	void addButton(const std::string key, float y, const std::string text);
	void updatePosition(sf::Vector2f viewCenter);
	void render(sf::RenderTarget& target);


};

