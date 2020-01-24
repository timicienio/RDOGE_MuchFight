#pragma once

#include "MainMenuState.h"

#include "GameState.h"
#include "GameState_PalmBoulevard.h"
#include "GameState_SportsField.h"
#include "GameState_Classroom.h"
#include "GameState_Farm.h"

#include "GameState_Playground.h"
#include "Button.h"
#include "mapPlayer.h"

class MapState :
	public State
{
private:
	//variables
	sf::Texture backgroundTexture;
	sf::Texture playerTexture;
	sf::RectangleShape background;
	sf::Font font;
	sf::View view;
	sf::Keyboard::Key currentKeyPressed;
	bool isPressed = false;

	std::map<std::string, Button*> buttons;
	MapPlayer* mapPlayer;

	sf::Clock dtTime;
	float deltaTime;
	bool canGo;

	sf::Vector2f* checkpoint[9];

	//functions
	void initMapPlayer();
	void initBackground();
	void initFonts();
	void initKeybinds();
	void initButtons();

	bool gameover = false;

public:
	MapState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~MapState();

	//functions

	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};