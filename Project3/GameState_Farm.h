#pragma once
#include "GameState.h"
class GameState_Farm :
	public GameState
{
private:

	//// functions
	// initializers
	void initBackground();
	void initPlatform();
	void initEntities();


public:

	GameState_Farm(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~GameState_Farm();

	//functions
};

