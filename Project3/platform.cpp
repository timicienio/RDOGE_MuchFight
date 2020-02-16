#include "Platform.h"

Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	size.x *= UNIT_LENGTH;
	size.y *= UNIT_LENGTH;

	position.x *= UNIT_LENGTH;
	position.y *= UNIT_LENGTH;

	//sets all the attributes needed for the platform
	body.setSize(size);
	body.setOrigin(size / 2.f);
	texture->setRepeated(true);
	body.setTexture(texture);
	body.setTextureRect(sf::IntRect(0, 0, (int)(body.getSize().x * 16 / 50), (int)(body.getSize().y * 16 / 50)));

	position.x += size.x / 2;
	position.y += size.y / 2;

	body.setPosition(position);
}

void Platform::render(sf::RenderTarget* target)
{
	target->draw(body);
}