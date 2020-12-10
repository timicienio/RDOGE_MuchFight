#pragma once
#include "GameState.h"
class GameState_SportsField :
	public GameState
{
private:

	//// functions
	// initializers
	void initBackground();


public:

	GameState_SportsField(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~GameState_SportsField();

	//functions

};

