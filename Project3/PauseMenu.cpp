#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::RenderWindow& window, sf::Font& font, Player* player)
	:font(font), view(window.getView())
{	
	//init background
	this->background.setSize(sf::Vector2f(static_cast<float>(window.getSize().x),
		static_cast<float>(window.getSize().y)));
	this->background.setFillColor(sf::Color(20, 20, 20, 0));
	
	
	this->container.setSize(sf::Vector2f(static_cast<float>(window.getSize().x) / 4.f,
		static_cast<float>(window.getSize().y) - 220.f));
	this->container.setFillColor(sf::Color(20, 20, 20, 125));
	this->container.setPosition(static_cast<float>(player->getPosition().x) - this->container.getSize().x / 2.f,
		static_cast<float>(player->getPosition().y) - this->container.getSize().y / 2.f );
//	this->container.setPosition(static_cast<float>(window.getSize().x) / 2.f - this->container.getSize().x / 2.f, 30.f);

	//init text
	this->menuText.setFont(font);
	this->menuText.setFillColor(sf::Color(255, 255, 255, 200));
	this->menuText.setCharacterSize(60);
	this->menuText.setString("PAUSED");
	this->menuText.setPosition(this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f,
		 this->container.getPosition().y + 40.f);


}

PauseMenu::~PauseMenu()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

std::map<std::string, Button*>& PauseMenu::getButtons()
{
	return this->buttons;
}


void PauseMenu::addButton(const std::string key, float y, const std::string text)
{
	float width = 250.f;
	float height = 60.f;
	float x = this->container.getPosition().x + this->container.getSize().x / 2.f - width / 2.f;
	
	this->buttons[key] = new Button(x, y, width, height, &this->font,
		text, 40, sf::Color::White,
		sf::Color(50, 50, 50, 125), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

}

void PauseMenu::updatePosition(sf::Vector2f viewCenter)
{
	this->container.setPosition(static_cast<float>(viewCenter.x) - this->container.getSize().x / 2.f,
		static_cast<float>(viewCenter.y) - this->container.getSize().y / 2.f);
	this->menuText.setPosition(this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f,
		this->container.getPosition().y + 40.f);
	this->buttons["QUIT0"]->updatePosition(this->container.getPosition().x + this->container.getSize().x / 2.f - 125.f, viewCenter.y + 200.f);
	this->buttons["QUIT"]->updatePosition(this->container.getPosition().x + this->container.getSize().x / 2.f - 125.f, viewCenter.y + 260.f);
}

void PauseMenu::render(sf::RenderTarget& target)
{
	target.draw(background);
	target.draw(container);

	for (auto &i : this->buttons)
	{
		i.second->render(target);
	}
	target.draw(this->menuText);
}
