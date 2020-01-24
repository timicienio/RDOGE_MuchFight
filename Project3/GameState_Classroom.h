#pragma once
#include "GameState.h"
class GameState_Classroom :
	public GameState
{
private:

	//// functions
	// initializers
	void initBackground();
	void initPlatform();
	void initEntities();


public:

	GameState_Classroom(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~GameState_Classroom();

	//functions

};

