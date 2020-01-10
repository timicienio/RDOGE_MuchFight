#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"

class Game
{
private:
	//variables
	sf::RenderWindow* window;
	sf::Event sfEvent;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;
	bool fullscreen;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;


	//initialization
	void initVariables();
	void initWindow();
	void initKeys();
	void initStates();

public:
	//constructors/destructors
	Game();
	virtual ~Game();


	//functions
	void endApplication();

	//update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//render
	void render();

	//core
	void run();
	

};

#endif
