#include "MapState.h"

//initializer functions
void MapState::initMapPlayer()
{
	playerTexture.loadFromFile("Resources/images/sprites/Player/DOGE.png");
	this->mapPlayer = new MapPlayer(&playerTexture, sf::Vector2u(8, 2), 0.07f, 200.0f);

	// mrt station
	this->checkpoint[0] = new sf::Vector2f(594.f, 757.f);
	// palm boulevard
	this->checkpoint[1] = new sf::Vector2f(594.f, 382.f);
	// playground
	this->checkpoint[2] = new sf::Vector2f(594.f, 38.f);
	// classroom
	this->checkpoint[3] = new sf::Vector2f(939.f, 38.f);

	this->checkpoint[4] = new sf::Vector2f(1245.f, 38.f);
	// library
	this->checkpoint[5] = new sf::Vector2f(1245.f, 338.f);
	// farm
	this->checkpoint[6] = new sf::Vector2f(1245.f, 618.f);
	// shinemood
	this->checkpoint[7] = new sf::Vector2f(822.f, 618.f);
	// college of management
	this->checkpoint[8] = new sf::Vector2f(822.f, 915.f);
}

void MapState::initBackground()
{
	this->background.setSize(sf::Vector2f
	(static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y)));

	this->backgroundTexture.loadFromFile("Resources/images/background/map.png");
	this->background.setTexture(&this->backgroundTexture);
}

void MapState::initFonts()
{
	this->font.loadFromFile("Fonts/ARCADECLASSIC.ttf");
	/*if (!this->font.loadFromFile("OpenSans-Light.ttf"));
	{
	throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}*/
}

void MapState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
	this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
	this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
	this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
	this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
	this->keybinds["MOVE_LEFT1"] = this->supportedKeys->at("Left");
	this->keybinds["MOVE_RIGHT1"] = this->supportedKeys->at("Right");
	this->keybinds["MOVE_UP1"] = this->supportedKeys->at("Up");
	this->keybinds["MOVE_DOWN1"] = this->supportedKeys->at("Down");

}

void MapState::initButtons()
{
	this->buttons["CHOOSE_STATE1_BTN"] = new Button(100.f, 1200.f, 535.f, 80.f, &this->font,
		"Press F1 to Start Game1", 40, sf::Color::White,
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
	this->buttons["EXIT_MAPSTATE_ BTN"] = new Button(1300.f, 150.f, 500.f, 100.f, &this->font,
		"Press Q to Quit", 60, sf::Color::White,
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

MapState::MapState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states), view(sf::Vector2f(960.f, 540.f), sf::Vector2f(1920.f, 1080.f))
{
	this->initMapPlayer();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
}

MapState::~MapState()
{
	for (int i = 0; i < 9; i++) {
		delete checkpoint[i];
	}
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
	delete mapPlayer;
}



void MapState::updateInput(const float& dt)
{
	this->deltaTime = this->dtTime.getElapsedTime().asSeconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		currentKeyPressed = sf::Keyboard::Left;
		isPressed = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		currentKeyPressed = sf::Keyboard::Right;
		isPressed = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		currentKeyPressed = sf::Keyboard::Down;
		isPressed = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		currentKeyPressed = sf::Keyboard::Up;
		isPressed = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		currentKeyPressed = sf::Keyboard::Enter;
		isPressed = true;
	}

	if (deltaTime > 1.3f) {
		dtTime.restart();
		canGo = true;
	}

	this->mapPlayer->update(dt, currentKeyPressed, isPressed, canGo);
	canGo = false;
	isPressed = false;
}

void MapState::updateButtons()
{
	//new game
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
	{
		this->states->push(new GameState_PalmBoulevard(this->window, this->supportedKeys, this->states));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
	{
		this->states->push(new GameState_SportsField(this->window, this->supportedKeys, this->states));
	}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
	//{
	//	this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	//}

	//quit the game
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		this->endState();
	}
}

void MapState::update(const float& dt)
{
	this->updateInput(dt);

	this->updateButtons();

	if ((abs(mapPlayer->getPosition().x - this->checkpoint[1]->x) < DIS && abs(mapPlayer->getPosition().y - this->checkpoint[1]->y) < DIS) && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		this->states->push(new GameState_PalmBoulevard(this->window, this->supportedKeys, this->states));
	}
	if ((abs(mapPlayer->getPosition().x - this->checkpoint[2]->x) < DIS && abs(mapPlayer->getPosition().y - this->checkpoint[2]->y) < DIS) && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		this->states->push(new GameState_Playground(this->window, this->supportedKeys, this->states));
	}
	if ((abs(mapPlayer->getPosition().x - this->checkpoint[3]->x) < DIS && abs(mapPlayer->getPosition().y - this->checkpoint[3]->y) < DIS) && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		this->states->push(new GameState_Classroom(this->window, this->supportedKeys, this->states));
	}
	/*if ((abs(mapPlayer->getPosition().x - this->checkpoint[5]->x) < DIS && abs(mapPlayer->getPosition().y - this->checkpoint[5]->y) < DIS) && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		this->states->push(new GameState_(this->window, this->supportedKeys, this->states));
	}*/
	if ((abs(mapPlayer->getPosition().x - this->checkpoint[6]->x) < DIS && abs(mapPlayer->getPosition().y - this->checkpoint[6]->y) < DIS) && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		this->states->push(new GameState_Farm(this->window, this->supportedKeys, this->states));
	}
	/*if ((abs(mapPlayer->getPosition().x - this->checkpoint[7]->x) < DIS && abs(mapPlayer->getPosition().y - this->checkpoint[7]->y) < DIS) && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}
	if ((abs(mapPlayer->getPosition().x - this->checkpoint[8]->x) < DIS && abs(mapPlayer->getPosition().y - this->checkpoint[8]->y) < DIS) && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}*/
}

void MapState::renderButtons(sf::RenderTarget* target)
{
	//this->renderButtons(target);
	for (auto& it : this->buttons)
	{
		it.second->render(*target);
	}
}

void MapState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);


	target->setView(view);
	this->renderButtons(target);

	this->mapPlayer->draw(target);
}