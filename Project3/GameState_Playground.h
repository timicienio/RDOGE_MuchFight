#pragma once

//#include <iostream>

#include "GameState.h"


class GameState_Playground :
	public GameState
{
private:

	//// functions
	// initializers
	void initBackground() override;


public:

	GameState_Playground(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~GameState_Playground();

	//functions

};

