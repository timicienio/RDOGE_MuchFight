#pragma once

#include <iostream>

#include "State.h"
#include "Bicycle.h"
#include "Maisy.h"
#include "NyanCat.h"
#include "WickedDoge.h"
#include "ShuiYuanABe.h"

#include "Platform.h"
#include "BlueFireBall.h"
#include "Goal.h"

#include "GameoverState.h"
#include "SuccessState.h"
#include "PauseMenu.h"
#include "PlayerHealthBar.h"
#include "GameoverState.h"
#include "SuccessState.h"


class GameState_Playground :
	public State
{
private:
	sf::Font font;
	PlayerHealthBar* playerHealthBar;
	PauseMenu* pmenu;
	GameoverState* gover;
	SuccessState* successmenu;

	int score = 0;
	bool setted = false;
	double timeInGame = 0.f;


	//// entities
	// player
	Player* player;

	// enemy vectors
	std::vector<Bicycle*> bicycles;
	std::vector<Maisy*> maisies;
	std::vector<NyanCat*> nyanCats;
	std::vector<WickedDoge*> wickedDoge;
	std::vector<ShuiYuanABe*> shuiYuanABes;

	// pointer of the boss entity
	Entity* boss;

	Goal* goal;
	//// objects
	// throwables
	std::vector<BlueFireBall*> blueFireBalls;

	// platforms
	std::vector<Platform> grass;
	std::vector<Platform> dirt;

	// platform index to be erased after defeating the boss
	unsigned int barrierPlatformIndex;
	bool erased = false;

	// x coordinate for success pole
	double successPoleXCoordinate;

	double successTime = 0.f;

	sf::Texture texture;
	sf::View view;
	sf::Vector2f viewCenter;


	sf::RectangleShape background;


	//// functions
	// initializers
	void initFonts();
	void initKeybinds();
	void initTexture();
	void initGUI();
	void initPauseMenu();
	void initGameoverState();
	void initSuccessState();


	void initBackground();
	void initPlayer();
	void initPlatform();
	void initEnemies();

	// platform collision
	void checkPlatformCollision();

	// collision between same type of enemy
	void checkSameTypeEnemyCollision();

	// near attack
	void checkPlayerEnemiesCollision();
	void checkDamage(Entity& enemy, sf::Vector2f direction);

	// far attack
	void checkThrow();
	//void checkPlayerThrow(Player& player, sf::Vector2f throwVelocity); // TODO
	//void checkEnemyThrow(Entity& enemy, sf::Vector2f throwVelocity);
	//void checkHit(BlueFireBall& blueFireBall);
	//bool checkHitPlatform(BlueFireBall& blueFireBall);
	////void checkHitEnemy(); // TODO
	bool checkHitPlayer(BlueFireBall& blueFireBall);

	// if boss is defeated, erase barrier platform
	void checkBossDefeated();

	bool checkSuccess();

	void checkGameOver();

	void clearDeadEnemies();

	//bool checkTreading(sf::Vector2f enemyVelocity);



public:


	std::vector<Platform> platforms;
	GameState_Playground(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~GameState_Playground();

	//functions

	void updateInput(const float& dt);
	void updatePlayerInput(const float& dt);
	void updatePauseMenuButtons();
	void updateGameoverStateButtons();
	void updateSuccessStateButtons();
	void updateView();
	void updateBackground();
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);

};

