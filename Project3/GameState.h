#pragma once

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

class GameState :
	public State
{
protected:
	sf::Font font;
	PlayerHealthBar* playerHealthBar;
	PauseMenu* pmenu;
	GameoverState* gover;
	SuccessState* successmenu;

	bool jumpKeyStateFlag;
	bool previousKeyState;

	int score = 0;
	bool setted = false;
	float timeInGame = 0.f;


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
	std::vector<Platform> platformWithCollision;
	std::vector<Platform> platformWithoutCollision;

	// platform index to be erased after defeating the boss
	unsigned int barrierPlatformIndex;
	bool erased = false;

	// x coordinate for success pole
	float successPoleXCoordinate;

	float successTime = 0.f;

	sf::Texture texture;
	sf::View view;
	sf::Vector2f viewCenter;

	sf::RectangleShape background;


	//// functions
	// initializers
	void initFonts();
	void initKeybinds();
	void initTexture();
	void initPauseMenu();
	void initGameoverState();
	void initSuccessState();


	virtual void initBackground() = 0;
	virtual void initPlatform() = 0;
	virtual void initEntities() = 0;

	void initGUI();


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

public:

	// constructor/destructor
	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	~GameState();

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

