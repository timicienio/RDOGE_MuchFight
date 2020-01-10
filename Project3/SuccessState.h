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


class SuccessState
{
private:
	sf::Font& font;
	sf::Texture backgroundTexture;
	sf::View view;
	sf::RectangleShape background;
	std::map<std::string, Button*> buttons;

	Player* player;
	sf::RectangleShape container;
	//private functions
	sf::Text menuText;
	sf::Text menuText2;

public:
	sf::Text score;

	SuccessState(sf::RenderWindow& window, sf::Font& font, Player* player);
	virtual ~SuccessState();

	//accessor
	std::map<std::string, Button*>& getButtons();


	//functions
	//	const bool isButtonPressed(const std::string key);
	void addButton(const std::string key, float y, const std::string text);
	void updatePosition(sf::Vector2f viewCenter);
	void render(sf::RenderTarget& target);


};