#include "GameoverState.h"

GameoverState::GameoverState(sf::RenderWindow& window, sf::Font& font, Player* player)
	:font(font), view(window.getView())
{
	//init background
	this->background.setSize(sf::Vector2f(static_cast<float>(window.getSize().x),
		static_cast<float>(window.getSize().y)));
	this->background.setFillColor(sf::Color::Black);


	this->container.setSize(sf::Vector2f(static_cast<float>(window.getSize().x) / 4.f,
		static_cast<float>(window.getSize().y) - 150.f));
	this->container.setFillColor(sf::Color::Black);
	this->container.setPosition(static_cast<float>(player->getPosition().x) - this->container.getSize().x / 2.f,
		static_cast<float>(player->getPosition().y) - this->container.getSize().y / 2.f);
	//	this->container.setPosition(static_cast<float>(window.getSize().x) / 2.f - this->container.getSize().x / 2.f, 30.f);

	//init text
	this->menuText.setFont(font);
	this->menuText.setFillColor(sf::Color(255, 255, 255, 200));
	this->menuText.setCharacterSize(120);
	this->menuText.setString("GAME OVER!!!");
	this->menuText.setPosition(this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f, this->container.getPosition().y + 400.f);

	this->player = player;
}

GameoverState::~GameoverState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

std::map<std::string, Button*>& GameoverState::getButtons()
{
	return this->buttons;
}


void GameoverState::addButton(const std::string key, float y, const std::string text)
{
	float width = 700.f;
	float height = 80.f;
	float x = this->container.getPosition().x + this->container.getSize().x / 2.f - width / 2.f;

	this->buttons[key] = new Button(x, y, width, height, &this->font,
		text, 40, sf::Color::White,
		sf::Color(100, 100, 100, 100), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

}

void GameoverState::updatePosition(sf::Vector2f viewCenter)
{
	this->background.setPosition(static_cast<float>(viewCenter.x) - 960.f, static_cast<float>(viewCenter.y) - 540.f);
	this->container.setPosition(static_cast<float>(viewCenter.x) - this->container.getSize().x / 2.f,
		static_cast<float>(viewCenter.y) - this->container.getSize().y / 2.f);
	this->menuText.setPosition(this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f,
		this->container.getPosition().y + 360.f);
	this->buttons["QUIT"]->updatePosition(this->container.getPosition().x + this->container.getSize().x / 2.f - 350.f, viewCenter.y + 180.f);
}

void GameoverState::render(sf::RenderTarget& target)
{
	this->score.setFont(font);
	this->score.setFillColor(sf::Color(255, 255, 255, 200));
	this->score.setPosition(this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f, this->container.getPosition().y + 480.f);
	//this->score.setString(std::to_string(this->player->score));
	this->score.setCharacterSize(80);

	target.draw(background);
	target.draw(container);
	target.draw(score);

	for (auto& i : this->buttons)
	{
		i.second->render(target);
	}
	target.draw(this->menuText);
}
