#include "MainMenuState.h"

//initializer functions
void MainMenuState::initVariables()
{

}

void MainMenuState::initBackground()
{
	this->background.setSize(sf::Vector2f
	(static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y)));
	this->background.setTexture(&textures["BACKGROUND"]);
	this->background.setOrigin(this->background.getSize().x / 2, this->background.getSize().y / 3);
	this->background.setPosition(sf::Vector2f(0.f, 0.f));
}

void MainMenuState::initFonts()
{
	this->font.loadFromFile("Fonts/ARCADECLASSIC.ttf");
	/*if (!this->font.loadFromFile("OpenSans-Light.ttf"));
	{
	throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}*/
}

void MainMenuState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
	this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("Left");
	this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("Right");
	this->keybinds["MOVE_UP"] = this->supportedKeys->at("Up");
	this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("Down");

}

void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE_ BTN"] = new Button(0.f, -175.f, 0.f, 0.f, &this->font,
		"RDOGE", 80, sf::Color::Black,
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
	this->buttons["GAME_STATE_ BTN2"] = new Button(0.f, -100.f, 0.f, 0.f, &this->font,
		"MUCH FIGHT", 80, sf::Color::Black,
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->flashButton = new Button(0.f, 0.f, 0.f, 200.f, &this->font,
		"Press   Enter   to   Start", 30, sf::Color::Black,
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

void MainMenuState::initPlayer()
{
	this->player = new Player(0.f, 0.f, this->textures["PLAYER"], 150.f);
}

void MainMenuState::initTexture()
{
	this->textures["PLAYER"].loadFromFile("Resources/images/sprites/Player/DOGE.png");
	this->textures["GRASS"].loadFromFile("Resources/images/sprites/GrassPart.png");
	this->textures["DIRT"].loadFromFile("Resources/images/sprites/DirtPart.png");
	this->textures["BACKGROUND"].loadFromFile("Resources/images/background/GameStateBackground.png");
}

void MainMenuState::initPlatforms()
{
	platforms.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(20.f, 1.f), sf::Vector2f(-10.f, 4.f)));
	platforms.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(20.f, 1.f), sf::Vector2f(-10.f, 5.f)));
	platforms.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(1.f, 10.f), sf::Vector2f(-10.f, -5.f)));
	platforms.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(1.f, 10.f), sf::Vector2f(9.f, -5.f)));
	platforms.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(20.f, 1.f), sf::Vector2f(-10, -6.f)));

}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states), view(sf::Vector2f(0.f, 0.f), sf::Vector2f(VIEW_WIDTH / 2, VIEW_HEIGHT / 2)), flash(false), flashTime(0.8f), jumpKeyStateFlag(false)
{
	this->initVariables();
	this->initTexture();
	this->initPlayer();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	this->initPlatforms();

}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}



void MainMenuState::updateInput(const float& dt)
{

}

void MainMenuState::updateButtons()
{
	//new game
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		this->states->push(new MapState(this->window, this->supportedKeys, this->states));
	}
	//if (this->buttons["GAME_STATE_ BTN"]->isPressed())
	//{
	//	this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	//} 


	//quit the game
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->endState();
	}
	//if (this->buttons["EXIT_STATE_ BTN"]->isPressed())
	//{
	//	this->quit = true;
	//}
}

void MainMenuState::updatePlayerInput(const float& dt)
{
	if ((previousKeyState == false && sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP")))) || previousKeyState == true && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP")))) {
		jumpKeyStateFlag = true;
	}
	else {
		jumpKeyStateFlag = false;
	}
	sf::Vector2f dir(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT")))) {
		dir.x += -1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT")))) {
		dir.x += 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP")))) {
		if (player->getMovementComponent()->getJumpedOnce()) {
			if (jumpKeyStateFlag == true) {
				dir.y += -1.f;
			}
		}
		else {
			dir.y += -1.f;
		}
		previousKeyState = true;
	}
	else {
		previousKeyState = false;
	}
	this->player->move(dir.x, dir.y, dt, player->canJump);
}

void MainMenuState::update(const float& dt)
{
	this->updateInput(dt);
	this->updatePlayerInput(dt);
	//	this->gamestate_btn->update();
	this->player->update(dt);
	sf::Vector2f direction;
	for (Platform& platform : platforms) {
		if (platform.getCollider().CheckCollision(this->player->getCollider(), direction, 1.f)) {
			player->onCollision(direction);
		}
	}
	this->updateButtons();
	this->updateFlash(dt);
}

void MainMenuState::updateFlash(const float& dt)
{
	totalTime += dt;
	if (totalTime > flashTime) {
		flash = (flash ? false : true);
		totalTime -= flashTime;
	}
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	//this->renderButtons(target);
	for (auto& it : this->buttons)
	{
		it.second->render(*target);
	}

}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->setView(this->view);
	target->draw(this->background);
	for (Platform& platform : platforms) {
		platform.render(target);
	}
	this->player->render(target);
	this->renderButtons(target);
	this->renderFlashButton(target);

	//	this->gamestate_btn->render(target);


}
