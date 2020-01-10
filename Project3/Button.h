#pragma once

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<sstream>


#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"

enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button
{
private:
	short unsigned buttonState;

	float x;
	float y;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;
	
	sf::Color textIdleColor;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;



public:
	Button(float x, float y, float width, float height,
		sf::Font* font, std::string text, unsigned character_size,
		sf::Color text_idle_color,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	~Button();

	//accessors
	const bool isPressed() const;


	//functions
	void update();
	void updatePosition(float x, float y);
	void render(sf::RenderTarget& target);

};

