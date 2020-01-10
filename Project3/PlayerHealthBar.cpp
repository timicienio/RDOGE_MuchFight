#include "PlayerHealthBar.h"


void PlayerHealthBar::initHearts(int maxHealth)
{
	for (int i = 0; i < maxHealth; i++)
	{
		this->hearts.push_back(sf::RectangleShape());
		hearts[i].setTexture(this->texture);
		hearts[i].setSize(heartSize);
		hearts[i].setPosition(heartPosition + sf::Vector2f(heartSpacing * i, 0));
	}
}

PlayerHealthBar::PlayerHealthBar(Player* player, sf::Texture* texture)
{
	this->player = player;
	this->texture = texture;
	this->heartSpacing = 60.f;
	this->heartPosition = sf::Vector2f(60.f, 60.f);
	this->heartSize = sf::Vector2f(40.f, 40.f);
	this->initHearts(this->player->getCombatComponent()->getMaxHealth());
}


PlayerHealthBar::~PlayerHealthBar()
{
}

void PlayerHealthBar::updatePosition(sf::Vector2f viewCenter)
{
	sf::Vector2f position;
	position.x = viewCenter.x - VIEW_WIDTH / 2 + heartPosition.x;
	position.y = viewCenter.y - VIEW_HEIGHT / 2 + heartPosition.y;

	for (int i = 0; i < this->player->getCombatComponent()->getCurrentHeath(); i++) 
	{
		this->hearts[i].setPosition(position);
		position.x += this->heartSpacing;
	}
}

void PlayerHealthBar::render(sf::RenderTarget& target)
{
	int currentHealth = this->player->getCombatComponent()->getCurrentHeath();

	for (int i = 0; i < currentHealth; ++i)
	{
		target.draw(this->hearts[i]);
	}
}
