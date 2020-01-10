#include "GameState_Playground.h"

void GameState_Playground::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
	this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("Left");
	this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("Right");
	this->keybinds["MOVE_UP"] = this->supportedKeys->at("Up");
}

void GameState_Playground::initTexture()
{

	this->textures["PLAYER_SHEET"].loadFromFile("Resources/images/sprites/Player/DOGE.png");
	this->textures["GRASS"].loadFromFile("Resources/images/sprites/GrassPart.png");
	this->textures["DIRT"].loadFromFile("Resources/images/sprites/DirtPart.png");
	this->textures["DIRT2"].loadFromFile("Resources/images/sprites/DirtPart2.png");
	this->textures["BLOCK"].loadFromFile("Resources/images/sprites/Block.png");
	this->textures["BRICK"].loadFromFile("Resources/images/sprites/Brick.png");
	this->textures["BRICK2"].loadFromFile("Resources/images/sprites/Brick2.png");
	this->textures["IRON"].loadFromFile("Resources/images/sprites/Iron.png");
	this->textures["BLOCK"].loadFromFile("Resources/images/sprites/Block.png");
	this->textures["BACKGROUND"].loadFromFile("Resources/images/background/GameStateBackground.png");
	this->textures["BICYCLE"].loadFromFile("Resources/images/sprites/Enemy/Bike Spritesheet.png");
	this->textures["NYANCAT"].loadFromFile("Resources/images/sprites/Enemy/Nyancat Spritesheet fade3.png");
	this->textures["MAISY"].loadFromFile("Resources/images/sprites/Enemy/maisySpritesheet.png");
	this->textures["WICKED_DOGE"].loadFromFile("Resources/images/sprites/Enemy/WickedDoge.png");
	this->textures["ABE"].loadFromFile("Resources/images/sprites/Enemy/ABESpritesheet.png");
	this->textures["FIREBALL"].loadFromFile("Resources/images/sprites/Attack/Fireball.png");
	this->textures["HEART"].loadFromFile("Resources/images/sprites/Heart.png");
	this->textures["GOAL"].loadFromFile("Resources/images/sprites/FlagpoleSpriteSheet.png");
}

void GameState_Playground::initGUI()
{
	this->playerHealthBar = new PlayerHealthBar(this->player, &this->textures["HEART"]);
}

void GameState_Playground::initPauseMenu()
{
	this->pmenu = new PauseMenu(*this->window, this->font, this->player);

	this->pmenu->addButton("QUIT0", this->viewCenter.y + 200.f, "Press  A ");
	this->pmenu->addButton("QUIT", this->viewCenter.y + 260.f, "to  Quit");
}

void GameState_Playground::initGameoverState()
{
	this->gover = new GameoverState(*this->window, this->font, this->player);

	this->gover->addButton("QUIT", this->viewCenter.y + 300.f, "PRESS  Z  TO  START  NEW  GAME");
}

void GameState_Playground::initSuccessState()
{
	this->successPoleXCoordinate = 50.f * UNIT_LENGTH;

	this->successmenu = new SuccessState(*this->window, this->font, this->player);

	this->successmenu->addButton("QUIT0", this->viewCenter.y + 200.f, "PRESS Z ");
	this->successmenu->addButton("QUIT1", this->viewCenter.y + 260.f, "TO     CONTINUE");
}

void GameState_Playground::initBackground()
{
	this->background.setSize(sf::Vector2f
	(static_cast<float>(this->window->getSize().x * 1.5f),
		static_cast<float>(this->window->getSize().y * 1.5f)));
	this->background.setTexture(&textures["BACKGROUND"]);
	this->background.setOrigin(this->background.getSize().x / 2, this->background.getSize().y / 3);
	this->background.setPosition(sf::Vector2f(0.f, 0.f));
}

void GameState_Playground::initPlatform()
{
	grass.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(8.f, 11.f)));
	grass.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(62.f, 1.f), sf::Vector2f(4.f, 5.f)));
	grass.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(62.f, 1.f), sf::Vector2f(4.f, 12.f)));
	grass.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 3.f), sf::Vector2f(7.f, 6.f)));
	grass.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 3.f), sf::Vector2f(16.f, 6.f)));
	grass.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 3.f), sf::Vector2f(20.f, 6.f)));
	grass.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 3.f), sf::Vector2f(29.f, 6.f)));
	grass.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 3.f), sf::Vector2f(33.f, 6.f)));
	grass.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 3.f), sf::Vector2f(42.f, 6.f)));
	grass.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 3.f), sf::Vector2f(46.f, 6.f)));
	grass.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 3.f), sf::Vector2f(55.f, 6.f)));
	grass.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(10.f, 1.f), sf::Vector2f(7.f, 9.f)));
	grass.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(10.f, 1.f), sf::Vector2f(20.f, 9.f)));
	grass.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(10.f, 1.f), sf::Vector2f(33.f, 9.f)));
	grass.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(10.f, 1.f), sf::Vector2f(46.f, 9.f)));



	goal = new Goal(&(this->textures["GOAL"]), sf::Vector2f(GOAL_WIDTH, GOAL_HEIGHT), sf::Vector2f(63.f * UNIT_LENGTH, 2.f * UNIT_LENGTH));

	barrierPlatformIndex = 0;
}

void GameState_Playground::initPlayer()
{
	this->player = new Player(7.f, 4.f, this->textures["PLAYER_SHEET"], 0.f);
}

void GameState_Playground::initEnemies()
{
	// Bicycles
	bicycles.push_back(new Bicycle(32.f, 10.f, this->textures["BICYCLE"], 0.f));
	bicycles.push_back(new Bicycle(42.f, 10.f, this->textures["BICYCLE"], 0.f));
	bicycles.push_back(new Bicycle(52.f, 10.f, this->textures["BICYCLE"], 0.f));
	

	// Maisies
	/*maisies.push_back(new Maisy(9.f, 6.f, this->textures["MAISY"], 60.f));
	maisies.push_back(new Maisy(11.f, 6.f, this->textures["MAISY"], 60.f));*/
	/*maisies.push_back(new Maisy(13.f, 6.f, this->textures["MAISY"], 60.f));
	maisies.push_back(new Maisy(8.f, 7.f, this->textures["MAISY"], 60.f));*/
	//maisies.push_back(new Maisy(10.f, 7.f, this->textures["MAISY"], 60.f));
	maisies.push_back(new Maisy(12.f, 7.f, this->textures["MAISY"], 60.f));
	maisies.push_back(new Maisy(14.f, 7.f, this->textures["MAISY"], 60.f));

	// Nyan Cats
	nyanCats.push_back(new NyanCat(35.f, 7.f, this->textures["NYANCAT"], 40.f));
	// nyanCats.push_back(new NyanCat(39.f, 7.f, this->textures["NYANCAT"], 40.f));

	// Wicked Doges
	wickedDoge.push_back(new WickedDoge(26.f, 7.f, this->textures["WICKED_DOGE"], 280.f));

	// Shui Yuan A Be's
	shuiYuanABes.push_back(new ShuiYuanABe(51.f, 6.f, this->textures["ABE"], 80.f));

	// set boss
	boss = nullptr;
}

void GameState_Playground::checkPlatformCollision()
{

	sf::Vector2f direction;

	for (Platform& platform : grass) {

		// thorwables

		for (unsigned int i = 0; i < blueFireBalls.size(); ++i)
		{
			if (blueFireBalls[i] != nullptr)
			{
				if (platform.getCollider().CheckCollision(blueFireBalls[i]->getCollider(), direction, 1.f))
				{
					delete blueFireBalls[i];
					blueFireBalls[i] = nullptr;
				}
			}
		}

		// player
		if (platform.getCollider().CheckCollision(player->getCollider(), direction, 1.f)) 
		{
			player->onCollision(direction);
		}

		//// enemies
		// bicycle
		for (unsigned int i = 0; i < bicycles.size(); ++i)
		{
			if (bicycles[i] != nullptr)
			{
				if (platform.getCollider().CheckCollision(bicycles[i]->getCollider(), direction, 1.f)) 
				{
					bicycles[i]->onCollision(direction);
				}
			}
		}

		for (unsigned int i = 0; i < maisies.size(); ++i)
		{
			if (maisies[i] != nullptr)
			{
				if (platform.getCollider().CheckCollision(maisies[i]->getCollider(), direction, 1.f)) 
				{
					maisies[i]->onCollision(direction);
				}
			}
		}

		for (unsigned int i = 0; i < nyanCats.size(); ++i)
		{
			if (nyanCats[i] != nullptr)
			{
				if (platform.getCollider().CheckCollision(nyanCats[i]->getCollider(), direction, 1.f)) 
				{
					nyanCats[i]->onCollision(direction);
				}
			}
		}

		for (unsigned int i = 0; i < wickedDoge.size(); ++i)
		{
			if (wickedDoge[i] != nullptr)
			{
				if (platform.getCollider().CheckCollision(wickedDoge[i]->getCollider(), direction, 1.f)) 
				{
					wickedDoge[i]->onCollision(direction);
				}
			}
		}

		for (unsigned int i = 0; i < shuiYuanABes.size(); ++i)
		{
			if (shuiYuanABes[i] != nullptr)
			{
				if (platform.getCollider().CheckCollision(shuiYuanABes[i]->getCollider(), direction, 1.f)) 
				{
					shuiYuanABes[i]->onCollision(direction);
				}
			}
		}

	}
}

void GameState_Playground::checkSameTypeEnemyCollision()
{
	sf::Vector2f direction;

	// bicycle
	for (unsigned int i = 0; i < bicycles.size(); ++i)
	{
		if (bicycles[i] != nullptr)
		{
			for (unsigned int j = 0; j < bicycles.size(); ++j)
			{
				if ((bicycles[j] != nullptr) && (i != j))
				{
					if (bicycles[i]->getCollider().CheckCollision(bicycles[j]->getCollider(), direction, 1.f)) 
					{
						bicycles[j]->onCollision(direction);
					}
				}
			}
		}
	}



	for (unsigned int i = 0; i < maisies.size(); ++i)
	{
		if (maisies[i] != nullptr)
		{
			for (unsigned int j = 0; j < maisies.size(); ++j)
			{
				if ((maisies[j] != nullptr) && (i != j))
				{
					if (maisies[i]->getCollider().CheckCollision(maisies[j]->getCollider(), direction, 1.f)) 
					{
						maisies[j]->onCollision(direction);
					}
				}
			}
		}
	}

	// nyan cat
	for (unsigned int i = 0; i < nyanCats.size(); ++i)
	{
		if (nyanCats[i] != nullptr)
		{
			for (unsigned int j = 0; j < nyanCats.size(); ++j)
			{
				if ((nyanCats[j] != nullptr) && (i != j))
				{
					if (nyanCats[i]->getCollider().CheckCollision(nyanCats[j]->getCollider(), direction, 1.f)) 
					{
						nyanCats[j]->onCollision(direction);
					}
				}
			}
		}
	}

	// wicked doge
	for (unsigned int i = 0; i < wickedDoge.size(); ++i)
	{
		if (wickedDoge[i] != nullptr)
		{
			for (unsigned int j = 0; j < wickedDoge.size(); ++j)
			{
				if ((wickedDoge[j] != nullptr) && (i != j))
				{
					if (wickedDoge[i]->getCollider().CheckCollision(wickedDoge[j]->getCollider(), direction, 1.f)) 
					{
						wickedDoge[j]->onCollision(direction);
					}
				}
			}
		}
	}

	// shui yuan a be
	for (unsigned int i = 0; i < shuiYuanABes.size(); ++i)
	{
		if (shuiYuanABes[i] != nullptr)
		{
			for (unsigned int j = 0; j < shuiYuanABes.size(); ++j)
			{
				if ((shuiYuanABes[j] != nullptr) && (i != j))
				{
					if (shuiYuanABes[i]->getCollider().CheckCollision(shuiYuanABes[j]->getCollider(), direction, 1.f)) 
					{
						shuiYuanABes[j]->onCollision(direction);
					}
				}
			}
		}
	}
}

void GameState_Playground::checkPlayerEnemiesCollision()
{
	sf::Vector2f direction;

	for (unsigned int i = 0; i < bicycles.size(); ++i)
	{
		if (bicycles[i] != nullptr)
		{
			if (this->player->getCollider().CheckCollision(bicycles[i]->getCollider(), direction, 1.f)) 
			{
				checkDamage(*(bicycles[i]), direction);
			}
		}
	}

	for (unsigned int i = 0; i < maisies.size(); ++i)
	{
		if (maisies[i] != nullptr)
		{
			if (this->player->getCollider().CheckCollision(maisies[i]->getCollider(), direction, 1.f)) 
			{
				checkDamage(*(maisies[i]), direction);
			}
		}
	}

	for (unsigned int i = 0; i < nyanCats.size(); ++i)
	{
		if (nyanCats[i] != nullptr)
		{
			if (this->player->getCollider().CheckCollision(nyanCats[i]->getCollider(), direction, 1.f)) 
			{
				checkDamage(*(nyanCats[i]), direction);
			}
		}
	}

	for (unsigned int i = 0; i < wickedDoge.size(); ++i)
	{
		if (wickedDoge[i] != nullptr)
		{
			if (this->player->getCollider().CheckCollision(wickedDoge[i]->getCollider(), direction, 1.f)) 
			{
				checkDamage(*(wickedDoge[i]), direction);
			}
		}
	}

	for (unsigned int i = 0; i < shuiYuanABes.size(); ++i)
	{
		if (shuiYuanABes[i] != nullptr)
		{
			if (this->player->getCollider().CheckCollision(shuiYuanABes[i]->getCollider(), direction, 1.f)) 
			{
				checkDamage(*(shuiYuanABes[i]), direction);
			}
		}
	}
}

void GameState_Playground::checkDamage(Entity& enemy, sf::Vector2f direction)
{
	if (direction.y == 0.f) // collision from side (player takes damage)
	{

		if (this->player->canTakeDamage)
		{
			if (enemy.canTakeDamage)
				enemy.playerOnEnemyCollision(direction);

			this->player->playerOnEnemyCollision(direction); // knockback

			this->player->getCombatComponent()->takeDamage(enemy.getCombatComponent()->getNearAttack());

			this->player->canTakeDamage = false;
			this->player->resetTimeSinceHurt();
		}
	}

	else if (direction.y > 0) // player on top
	{

		if (enemy.canTakeDamage)
		{
			this->player->playerOnEnemyCollision(direction); // knockback player
			enemy.playerOnEnemyCollision(direction); // knockback enemy

			enemy.getCombatComponent()->takeDamage(this->player->getCombatComponent()->getNearAttack());

			enemy.canTakeDamage = false;
			enemy.resetTimeSinceHurt();
		}
	}

	else if (this->player->canTakeDamage) // enemy on top
	{
		enemy.playerOnEnemyCollision(direction);

		this->player->playerOnEnemyCollision(direction); // knockback

		this->player->getCombatComponent()->takeDamage(enemy.getCombatComponent()->getNearAttack());

		this->player->canTakeDamage = false;
		this->player->resetTimeSinceHurt();
	}
}

void GameState_Playground::checkThrow()
{
	for (unsigned int i = 0; i < this->nyanCats.size(); ++i)
	{
		if (nyanCats[i] != nullptr)
		{
			sf::Vector2f throwableSize;
			throwableSize.x = 0.2f * UNIT_LENGTH;
			throwableSize.y = 0.2f * UNIT_LENGTH;

			const sf::Vector2f throwVelocity = this->nyanCats[i]->getAutomationComponent()->getCurrentAgression()->getCurrentAgressOutput();

			if (throwVelocity.x != 0.f) // there is throw
			{
				blueFireBalls.push_back(new BlueFireBall(nullptr, throwableSize, this->nyanCats[i]->getPosition(), throwVelocity, this->nyanCats[i]->getCombatComponent()->getFarAttack(), this->nyanCats[i]->getCombatComponent()->getFarAttackRange())); // generate a new throwable
			}
		}
	}

	for (unsigned int i = 0; i < this->shuiYuanABes.size(); ++i)
	{
		if (shuiYuanABes[i] != nullptr)
		{
			sf::Vector2f throwableSize(THROWABLE_WIDTH, THROWABLE_HEIGHT);

			const sf::Vector2f throwVelocity = this->shuiYuanABes[i]->getAutomationComponent()->getCurrentAgression()->getCurrentAgressOutput();

			if (throwVelocity.x != 0.f) // there is throw
			{
				blueFireBalls.push_back(new BlueFireBall(&this->textures["FIREBALL"], throwableSize, this->shuiYuanABes[i]->getPosition(), throwVelocity, this->shuiYuanABes[i]->getCombatComponent()->getFarAttack(), this->shuiYuanABes[i]->getCombatComponent()->getFarAttackRange())); // generate a new throwable
			}
		}
	}
}


bool GameState_Playground::checkHitPlayer(BlueFireBall& blueFireBall)
{
	sf::Vector2f direction; // won't be used

	if (this->player->getCollider().CheckCollision(blueFireBall.getCollider(), direction, 1.f))
	{
		if (this->player->canTakeDamage)
		{
			sf::Vector2f throwableVelocity = blueFireBall.getVelocity();
			throwableVelocity.x = -throwableVelocity.x; 

			this->player->playerOnEnemyCollision(throwableVelocity); // knockback

			this->player->getCombatComponent()->takeDamage(blueFireBall.getDamage());

			this->player->canTakeDamage = false;
			this->player->resetTimeSinceHurt();
		}

		return true;
	}

	return false;
}

void GameState_Playground::checkBossDefeated()
{
	if ((this->boss == nullptr && !this->erased)) // is deleted
	{
		this->grass.erase(grass.begin() + barrierPlatformIndex);
		this->erased = true;
	}
}

bool GameState_Playground::checkSuccess()
{
	if (this->player->getPosition().x >= successPoleXCoordinate)
	{
		return true;
	}

	return false;
}

//void GameState::checkEnemyThrow(Entity& enemy, sf::Vector2f throwVelocity)
//{
//
//}

void GameState_Playground::checkGameOver()
{
	if (!(this->player->getCombatComponent()->getIsAlive()) || player->getPosition().y > 10.f * UNIT_LENGTH) // game over
	{
		this->gameover = true;
		//this->states->push(new GameoverState(this->window, this->supportedKeys, this->states));
	}

}



void GameState_Playground::clearDeadEnemies()
{
	for (unsigned int i = 0; i < bicycles.size(); ++i)
	{
		if (bicycles[i] != nullptr)
		{
			if (!(bicycles[i]->getCombatComponent()->getIsAlive()))
			{
				delete bicycles[i];
				bicycles[i] = nullptr;

				this->score += BICYCLE_SCORE;
			}
		}

	}

	for (unsigned int i = 0; i < maisies.size(); ++i)
	{
		if (maisies[i] != nullptr)
		{
			if (!(maisies[i]->getCombatComponent()->getIsAlive()))
			{
				delete maisies[i];
				maisies[i] = nullptr;

				this->score += MAISY_SCORE;
			}
		}
	}

	for (unsigned int i = 0; i < nyanCats.size(); ++i)
	{
		if (nyanCats[i] != nullptr)
		{
			if (!(nyanCats[i]->getCombatComponent()->getIsAlive()))
			{
				delete nyanCats[i];
				nyanCats[i] = nullptr;

				this->score += NYANCAT_SCORE;
			}
		}
	}

	for (unsigned int i = 0; i < wickedDoge.size(); ++i)
	{
		if (wickedDoge[i] != nullptr)
		{
			if (!(wickedDoge[i]->getCombatComponent()->getIsAlive()))
			{
				delete wickedDoge[i];
				wickedDoge[i] = nullptr;

				this->score += WICKED_DOGE_SCORE;
			}
		}
	}

	for (unsigned int i = 0; i < shuiYuanABes.size(); ++i)
	{
		if (shuiYuanABes[i] != nullptr)
		{
			if (!(shuiYuanABes[i]->getCombatComponent()->getIsAlive()))
			{
				delete shuiYuanABes[i];
				shuiYuanABes[i] = nullptr;
				this->boss = nullptr;

				this->score += SHUIYUANABE_SCORE;
			}
		}
	}
}

void GameState_Playground::initFonts()
{
	this->font.loadFromFile("Fonts/ARCADECLASSIC.ttf");
	/*if (!this->font.loadFromFile("OpenSans-Light.ttf"));
	{
	throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}*/
}


GameState_Playground::GameState_Playground(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states) ,view(sf::Vector2f(0.f,0.f), sf::Vector2f(1920.f,1080.f))
{
	this->initKeybinds();
	this->initFonts();
	this->initTexture();

	this->initBackground();
	this->initPlayer();
	this->initPlatform();
	this->initEnemies();

	this->initGUI();
	this->initPauseMenu();
	this->initGameoverState();
	this->initSuccessState();
}

GameState_Playground::~GameState_Playground()
{
	delete this->player;


	for (unsigned int i = 0; i < bicycles.size(); ++i)
	{
		if (bicycles[i] != nullptr) delete bicycles[i];
	}

	for (unsigned int i = 0; i < maisies.size(); ++i)
	{
		if (maisies[i] != nullptr) delete maisies[i];
	}

	for (unsigned int i = 0; i < nyanCats.size(); ++i)
	{
		if (nyanCats[i] != nullptr) delete nyanCats[i];
	}

	for (unsigned int i = 0; i < wickedDoge.size(); ++i)
	{
		if (wickedDoge[i] != nullptr) delete wickedDoge[i];
	}

	for (unsigned int i = 0; i < shuiYuanABes.size(); ++i)
	{
		if (shuiYuanABes[i] != nullptr) delete shuiYuanABes[i];
	}

	delete this->pmenu;
	delete this->gover;
	delete this->successmenu;
}


void GameState_Playground::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeytime() && !success && !gameover)
	{
		
		if (!this->paused)
		{
			pmenu->updatePosition(viewCenter);          //UPDATE PAUSE MENU CONTAINER POSITION
			this->pauseState();
		}
		else
		{
			this->unpauseState();
		}
	}
}

void GameState_Playground::updatePlayerInput(const float& dt)
{
	sf::Vector2f dir(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT")))) {
		dir.x += -1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT")))) {
		dir.x += 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP")))) {
		dir.y += -1.f;
		this->player->move(dir.x, dir.y, dt, player->canJump);
		this->player->canJump = false;
	}
	else {
		this->player->move(dir.x, dir.y, dt, player->canJump);
	}
}

void GameState_Playground::updatePauseMenuButtons()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //in pause state, press A to quit
	{
		this->endState();
	}
}

void GameState_Playground::updateGameoverStateButtons()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) //in gameover state, press Z to quit
	{
		this->endState();
	}
}

void GameState_Playground::updateSuccessStateButtons()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) //in success state, press Z to quit
	{
		this->endState();
	}
}

void GameState_Playground::updateView()
{
	this->viewCenter = player->getPosition();
	if (this->viewCenter.y < 400.f && this->viewCenter.y > -100.f) {
		this->viewCenter.y = 100.f;
	}
	else if (this->viewCenter.y < -100.f) {
		this->viewCenter.y += 200.f;
	}
	else if (this->viewCenter.y > 400.f) {
		this->viewCenter.y -= 300.f;
	}
	if (this->viewCenter.x < 1100.f) {
		this->viewCenter.x = 1100.f;
	}
	//	else if (this->viewCenter.x > 300.f) {
	//		this->viewCenter.x = 300.f;
	//	}
	view.setCenter(this->viewCenter);
}

void GameState_Playground::updateBackground()
{
	this->background.setPosition(viewCenter);
}

void GameState_Playground::update(const float& dt)
{
	this->updateKeytime(dt);
	this->updateInput(dt);

	this->timeInGame += dt;

	// check if successed
	if (this->boss == nullptr)
	{
		if (this->checkSuccess())
		{
			successTime += dt;

			if (successTime > 3.f) // stay in game state for a while
								   // push state
			{
				this->success = true;
			}
		}
	}

	if (this->gameover)
	{
		this->score -= static_cast<int>(this->timeInGame) * TIME_DEDUCTION;

		if (!this->setted) 
		{
			this->setted = true;
			this->gover->score.setString(std::to_string(this->score));
		}

		this->gameoverState();
		gover->updatePosition(viewCenter);
	}
	if (this->success)
	{
		this->score += this->player->getCombatComponent()->getCurrentHeath() * HEART_BONUS;
		this->score -= static_cast<int>(this->timeInGame) * TIME_DEDUCTION;
		this->player->score = this->score;

		if (!this->setted) 
		{
			this->setted = true;
			this->successmenu->score.setString(std::to_string(this->score));
		}

		this->successState();
		successmenu->updatePosition(viewCenter);
	}

	// entities' collision with platforms
	this->checkPlatformCollision();

	if (!this->paused && !this->gameover && !this->success) //in game
	{
		this->updatePlayerInput(dt);

		this->player->update(dt);

		for(unsigned int i = 0; i < blueFireBalls.size(); ++i)
		{
			if (blueFireBalls[i] != nullptr)
			{
				if ((blueFireBalls[i]->getPosition().x > viewCenter.x - 1200.f && blueFireBalls[i]->getPosition().x < viewCenter.x + 1200.f) && !blueFireBalls[i]->outOfRange())
					// updates objects within the x-axis range of 2400 and not out of attack range
				{
					blueFireBalls[i]->update(dt);
					if (checkHitPlayer(*(blueFireBalls[i])))
					{
						delete blueFireBalls[i];
						blueFireBalls[i] = nullptr;
					}
				}
				else // clear this throwable
				{
					delete blueFireBalls[i];
					blueFireBalls[i] = nullptr;
				}
			}

		}

		for (unsigned int i = 0; i < bicycles.size(); ++i)
		{
			if (bicycles[i] != nullptr)
			{
				if (bicycles[i]->getPosition().x > viewCenter.x - 1200.f && bicycles[i]->getPosition().x < viewCenter.x + 1200.f) 
					// updates enemies withinn the x-axis range of 2400
				{
					bicycles[i]->update(dt);

					const sf::Vector2f tempMovementOutput = bicycles[i]->getAutomationComponent()->getCurrentAction()->getCurrentMovementOutput();

					bicycles[i]->move(tempMovementOutput.x, tempMovementOutput.y, dt, bicycles[i]->canJump);
				}
			}
		}

		for (unsigned int i = 0; i < maisies.size(); ++i)
		{
			if (maisies[i] != nullptr)
			{
				if(maisies[i]->getPosition().x > viewCenter.x - 1200.f && maisies[i]->getPosition().x < viewCenter.x + 1200.f)
				{
					// let the enemy "see" the player
					maisies[i]->getAutomationComponent()->getCurrentAction()->setChaseTargetPosition(this->player->getPosition());


					const sf::Vector2f tempMovementOutput = maisies[i]->getAutomationComponent()->getCurrentAction()->getCurrentMovementOutput();

					maisies[i]->move(tempMovementOutput.x, tempMovementOutput.y, dt, maisies[i]->canJump);

					maisies[i]->update(dt);

					if (tempMovementOutput.y == -1.f)
					{
						maisies[i]->canJump = false;
					}
				}
			}
		}

		for (unsigned int i = 0; i < nyanCats.size(); ++i)
		{
			if (nyanCats[i] != nullptr)
			{
				if(nyanCats[i]->getPosition().x > viewCenter.x - 1200.f && nyanCats[i]->getPosition().x < viewCenter.x + 1200.f)
				{
					// let the enemy "see" the player
					nyanCats[i]->getAutomationComponent()->getCurrentAction()->setChaseTargetPosition(this->player->getPosition());


					const sf::Vector2f tempMovementOutput = nyanCats[i]->getAutomationComponent()->getCurrentAction()->getCurrentMovementOutput();

					nyanCats[i]->move(tempMovementOutput.x, tempMovementOutput.y, dt, nyanCats[i]->canJump);

					nyanCats[i]->update(dt);

					if (tempMovementOutput.y == -1.f)
					{
						nyanCats[i]->canJump = false;
					}
				}
			}
		}

		for (unsigned int i = 0; i < wickedDoge.size(); ++i)
		{
			if (wickedDoge[i] != nullptr)
			{
				if(wickedDoge[i]->getPosition().x > viewCenter.x - 1200.f && wickedDoge[i]->getPosition().x < viewCenter.x + 1200.f)
				{
					// let the enemy "see" the player
					wickedDoge[i]->getAutomationComponent()->getCurrentAction()->setChaseTargetPosition(this->player->getPosition());


					const sf::Vector2f tempMovementOutput = wickedDoge[i]->getAutomationComponent()->getCurrentAction()->getCurrentMovementOutput();

					wickedDoge[i]->move(tempMovementOutput.x, tempMovementOutput.y, dt, wickedDoge[i]->canJump);

					wickedDoge[i]->update(dt);

					if (tempMovementOutput.y == -1.f)
					{
						wickedDoge[i]->canJump = false;
					}
				}
			}
		}

		for (unsigned int i = 0; i < shuiYuanABes.size(); ++i)
		{
			if (shuiYuanABes[i] != nullptr)
			{
				if(shuiYuanABes[i]->getPosition().x > viewCenter.x - 1200.f && shuiYuanABes[i]->getPosition().x < viewCenter.x + 1200.f)
				{
					// let the enemy "see" the player
					shuiYuanABes[i]->getAutomationComponent()->getCurrentAction()->setChaseTargetPosition(this->player->getPosition());


					const sf::Vector2f tempMovementOutput = shuiYuanABes[i]->getAutomationComponent()->getCurrentAction()->getCurrentMovementOutput();

					shuiYuanABes[i]->move(tempMovementOutput.x, tempMovementOutput.y, dt, shuiYuanABes[i]->canJump);

					shuiYuanABes[i]->update(dt);

					if (tempMovementOutput.y == -1.f)
					{
						shuiYuanABes[i]->canJump = false;
					}
				}
			}
		}
	}

	else if (this->success == true)
	{
		this->updateSuccessStateButtons();
	}
	else
	{
		this->updatePauseMenuButtons();
		this->updateGameoverStateButtons();
	}

	this->goal->updateGoal(dt, this->checkSuccess());

	// clear dead enemies
	this->clearDeadEnemies();

	// check if boss is defeated
	this->checkBossDefeated();


	// checks collisions between same types of enmies
	this->checkSameTypeEnemyCollision();

	// player's collision with enemies (also checks harm and take damage)
	this->checkPlayerEnemiesCollision();


	// check if there's new throwables being generated
	this->checkThrow();

	// update player-specific variables
	this->player->updateStatus(dt);

	// update enemies with far attack
	for (unsigned int i = 0; i < shuiYuanABes.size(); i++)
	{
		if (nyanCats[i] != nullptr)
		{
			this->nyanCats[i]->updateStatus(dt);
		}

		if (wickedDoge[i] != nullptr)
		{
			this->wickedDoge[i]->updateStatus(dt);
		}

		if (shuiYuanABes[i] != nullptr)
		{
			this->shuiYuanABes[i]->updateStatus(dt);
		}
	}


	// check game over
	this->checkGameOver();


	this->updateView();

	this->updateBackground();

	// update healthbar position
	this->playerHealthBar->updatePosition(this->viewCenter);
}

void GameState_Playground::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->setView(this->view);
	target->draw(this->background);


	for (Platform& platform : dirt)
	{
		platform.render(target);
	}

	for (Platform& platform : grass) 
	{
		platform.render(target);
	}

	goal->render(target);

	for (unsigned int i = 0; i < blueFireBalls.size(); ++i)
	{
		if (blueFireBalls[i] != nullptr)
			blueFireBalls[i]->render(target);
	}


	for (unsigned int i = 0; i < bicycles.size(); ++i)
	{
		if (bicycles[i] != nullptr)
			bicycles[i]->render(target);
	}

	for (unsigned int i = 0; i < maisies.size(); ++i)
	{
		if (maisies[i] != nullptr)
			maisies[i]->render(target);
	}

	for (unsigned int i = 0; i < nyanCats.size(); i++)
	{
		if (nyanCats[i] != nullptr)
			nyanCats[i]->render(target);
	}

	for (unsigned int i = 0; i < wickedDoge.size(); i++)
	{
		if (wickedDoge[i] != nullptr)
			wickedDoge[i]->render(target);
	}

	for (unsigned int i = 0; i < shuiYuanABes.size(); i++)
	{
		if (shuiYuanABes[i] != nullptr)
			shuiYuanABes[i]->render(target);
	}

	this->player->render(target);

	playerHealthBar->render(*target);

	if (this->paused) //pause state
	{
		this->pmenu->render(*target);

	}
	else if (this->gameover)
	{
		this->gover->render(*target);
	}
	else if (this->success)
	{
		this->successmenu->render(*target);
	}

}