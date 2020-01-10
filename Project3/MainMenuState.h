#pragma once 
#include "MapState.h"
#include "GameState.h"
#include "Button.h"
#include "Player.h"
#include "platform.h"

class MainMenuState :
	public State
{
private:
	//variables
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font font;
	sf::View view;

	Player* player;

	Button* flashButton;
	bool flash;
	float flashTime;
	float totalTime = 0;

	std::map<std::string, Button*> buttons;

	std::vector<Platform> platforms;

	bool pressEnter;

	//functions
	void initVariables();
	void initBackground();
	void initFonts();
	void initKeybinds();
	void initButtons();
	void initPlayer();
	void initTexture();
	void initPlatforms();


public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~MainMenuState();

	//functions

	void updateInput(const float& dt);
	void updateButtons();
	void updatePlayerInput(const float& dt);
	void update(const float& dt);
	void updateFlash(const float& dt);
	void renderButtons(sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
	void renderFlashButton(sf::RenderTarget* target) {
		if (!flash) {
			flashButton->render(*target);
		}
	}

};
