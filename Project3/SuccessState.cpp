#include "SuccessState.h"

SuccessState::SuccessState(sf::RenderWindow& window, sf::Font& font, Player* player)
	:font(font), view(window.getView())
{
	//init background
	this->background.setSize(sf::Vector2f(static_cast<float>(window.getSize().x),
		static_cast<float>(window.getSize().y)));
	//	this->background.setFillColor(sf::Color::Black);
	this->backgroundTexture.loadFromFile("Resources/images/background/successState.png");
	this->background.setTexture(&this->backgroundTexture);

	this->container.setSize(sf::Vector2f(static_cast<float>(window.getSize().x) / 4.f,
		static_cast<float>(window.getSize().y) - 220.f));
	this->container.setFillColor(sf::Color(20, 20, 20, 125));
	this->container.setPosition(static_cast<float>(player->getPosition().x) - this->container.getSize().x / 2.f,
		static_cast<float>(player->getPosition().y) - this->container.getSize().y / 2.f);
	//	this->container.setPosition(static_cast<float>(window.getSize().x) / 2.f - this->container.getSize().x / 2.f, 30.f);

	//init text
	this->menuText.setFont(font);
	this->menuText.setFillColor(sf::Color(255, 255, 255, 255));
	this->menuText.setCharacterSize(90);
	this->menuText.setString("YOU  WIN");
	this->menuText.setPosition(this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f,
		this->container.getPosition().y + 40.f);

	this->menuText2.setFont(font);
	this->menuText2.setFillColor(sf::Color(255, 255, 255, 255));
	this->menuText2.setCharacterSize(70);
	this->menuText2.setString("SCORE");
	this->menuText2.setPosition(this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f,
		this->container.getPosition().y + 170.f);



	this->player = player;
}

SuccessState::~SuccessState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

std::map<std::string, Button*>& SuccessState::getButtons()
{
	return this->buttons;
}


void SuccessState::addButton(const std::string key, float y, const std::string text)
{
	float width = 300.f;
	float height = 60.f;
	float x = this->container.getPosition().x + this->container.getSize().x / 2.f - width / 2.f;

	this->buttons[key] = new Button(x, y, width, height, &this->font,
		text, 40, sf::Color::White,
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

}

void SuccessState::updatePosition(sf::Vector2f viewCenter)
{
	this->container.setPosition(static_cast<float>(viewCenter.x) - this->container.getSize().x / 2.f,
		static_cast<float>(viewCenter.y) - this->container.getSize().y / 2.f);
	this->menuText.setPosition(this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f,
		this->container.getPosition().y + 40.f);
	this->menuText2.setPosition(this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText2.getGlobalBounds().width / 2.f,
		this->container.getPosition().y + 170.f);
	this->score.setPosition(this->container.getPosition().x + this->container.getSize().x / 2.f - this->score.getGlobalBounds().width / 2.f,
		this->container.getPosition().y + 240.f);
	//	this->background.setPosition(static_cast<float>(viewCenter.x) - 960.f, static_cast<float>(viewCenter.y) - 540.f);
	this->buttons["QUIT0"]->updatePosition(this->container.getPosition().x + this->container.getSize().x / 2.f - 150.f, viewCenter.y + 200.f);
	this->buttons["QUIT1"]->updatePosition(this->container.getPosition().x + this->container.getSize().x / 2.f - 150.f, viewCenter.y + 260.f);

}

void SuccessState::render(sf::RenderTarget& target)
{
	this->score.setFont(font);
	this->score.setFillColor(sf::Color(255, 255, 255, 255));
	//	this->score.setPosition(this->background.getPosition().x + this->background.getSize().x / 2.f / 2.f, this->background.getPosition().y + 480.f);
	//this->score.setString(std::to_string(this->player->score));
	this->score.setCharacterSize(70);

	//target.draw(background);
	target.draw(container);
	for (auto& i : this->buttons)
	{
		i.second->render(target);
	}
	target.draw(this->menuText);
	target.draw(this->menuText2);
	target.draw(score);
}