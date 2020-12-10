#include "GameState_PalmBoulevard.h"

void GameState_PalmBoulevard::initBackground()
{
	this->background.setSize(sf::Vector2f
	(static_cast<float>(this->window->getSize().x * 1.5f),
		static_cast<float>(this->window->getSize().y * 1.5f)));
	this->background.setTexture(&textures["BACKGROUND"]);
	this->background.setOrigin(this->background.getSize().x / 2, this->background.getSize().y / 3);
	this->background.setPosition(sf::Vector2f(0.f, 0.f));
}

GameState_PalmBoulevard::GameState_PalmBoulevard(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: GameState(window, supportedKeys, states)
{
	this->loadMap(std::string("Map/palm-boulevard.txt"));

	this->initKeybinds();
	this->initFonts();
	this->initTexture();

	this->initGUI();
	this->initBackground();
	this->initPauseMenu();
	this->initGameoverState();
	this->initSuccessState();
}

GameState_PalmBoulevard::~GameState_PalmBoulevard()
{
}