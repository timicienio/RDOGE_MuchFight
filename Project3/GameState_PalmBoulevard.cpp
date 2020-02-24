#include "GameState_PalmBoulevard.h"

void GameState_PalmBoulevard::initBackground()
{
	this->background.setSize(sf::Vector2f
	(static_cast<float>(this->window->getSize().x * 1.5f),
		static_cast<float>(this->window->getSize().y * 1.5f)));
	this->background.setTexture(&textures["BACKGROUND"]);
	this->background.setOrigin(this->background.getSize().x / 2, this->background.getSize().y / 3);
	this->background.setPosition(sf::Vector2f(0.f, 0.f));
}

void GameState_PalmBoulevard::initPlatform()
{
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(1.f, 8.f), sf::Vector2f(271.f, 8.f)));
	
	platformWithCollision.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(191.f, 11.f), sf::Vector2f(128.f, 26.f)));
	platformWithCollision.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(48.f, 11.f), sf::Vector2f(64.f, 26.f)));
	platformWithCollision.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(34.f, 11.f), sf::Vector2f(0.f, 26.f)));
	platformWithCollision.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(23.f, 11.f), sf::Vector2f(37.f, 26.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(190.f, 1.f), sf::Vector2f(129.f, 25.f)));
	platformWithCollision.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(16.f, 6.f), sf::Vector2f(112.f, 31.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["DIRT2"]), sf::Vector2f(27.f, 3.f), sf::Vector2f(151.f, 22.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(8.f, 9.f), sf::Vector2f(60.f, 12.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(18.f, 3.f), sf::Vector2f(52.f, 5.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(17.f, 3.f), sf::Vector2f(60.f, 22.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(9.f, 5.f), sf::Vector2f(236.f, 20.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(9.f, 5.f), sf::Vector2f(267.f, 20.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(22.f, 2.f), sf::Vector2f(50.f, 3.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(43.f, 1.f), sf::Vector2f(77.f, 25.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(13.f, 3.f), sf::Vector2f(46.f, 17.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(9.f, 4.f), sf::Vector2f(50.f, 12.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(6.f, 6.f), sf::Vector2f(69.f, 10.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(34.f, 1.f), sf::Vector2f(0.f, 25.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["DIRT2"]), sf::Vector2f(16.f, 2.f), sf::Vector2f(155.f, 20.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(8.f, 4.f), sf::Vector2f(47.f, 21.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(6.f, 5.f), sf::Vector2f(69.f, 17.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["DIRT2"]), sf::Vector2f(9.f, 3.f), sf::Vector2f(97.f, 22.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["DIRT2"]), sf::Vector2f(10.f, 2.f), sf::Vector2f(113.f, 28.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(16.f, 1.f), sf::Vector2f(155.f, 18.f)));
	platformWithCollision.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(16.f, 1.f), sf::Vector2f(155.f, 19.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(8.f, 2.f), sf::Vector2f(49.f, 8.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(8.f, 2.f), sf::Vector2f(65.f, 8.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(15.f, 1.f), sf::Vector2f(45.f, 25.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(14.f, 1.f), sf::Vector2f(54.f, 10.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(14.f, 1.f), sf::Vector2f(54.f, 11.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(13.f, 1.f), sf::Vector2f(64.f, 25.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 13.f), sf::Vector2f(59.f, 12.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(12.f, 1.f), sf::Vector2f(112.f, 30.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(6.f, 2.f), sf::Vector2f(47.f, 10.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(4.f, 3.f), sf::Vector2f(46.f, 14.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(4.f, 3.f), sf::Vector2f(55.f, 20.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(5.f, 2.f), sf::Vector2f(238.f, 18.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(5.f, 2.f), sf::Vector2f(269.f, 18.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["DIRT2"]), sf::Vector2f(5.f, 2.f), sf::Vector2f(146.f, 23.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["DIRT2"]), sf::Vector2f(5.f, 2.f), sf::Vector2f(178.f, 23.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(9.f, 1.f), sf::Vector2f(97.f, 21.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["DIRT2"]), sf::Vector2f(3.f, 3.f), sf::Vector2f(122.f, 25.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(8.f, 1.f), sf::Vector2f(69.f, 16.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(8.f, 1.f), sf::Vector2f(60.f, 21.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(8.f, 1.f), sf::Vector2f(37.f, 25.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(8.f, 1.f), sf::Vector2f(112.f, 27.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(4.f, 2.f), sf::Vector2f(193.f, 23.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(4.f, 2.f), sf::Vector2f(217.f, 23.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 8.f), sf::Vector2f(45.f, 12.f)));
	platformWithCollision.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(7.f, 1.f), sf::Vector2f(112.f, 26.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(6.f, 1.f), sf::Vector2f(53.f, 16.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(6.f, 1.f), sf::Vector2f(123.f, 22.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(3.f, 2.f), sf::Vector2f(48.f, 5.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(3.f, 2.f), sf::Vector2f(71.f, 5.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(3.f, 2.f), sf::Vector2f(46.f, 7.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(3.f, 2.f), sf::Vector2f(73.f, 7.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(3.f, 2.f), sf::Vector2f(44.f, 9.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(3.f, 2.f), sf::Vector2f(75.f, 9.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(3.f, 2.f), sf::Vector2f(233.f, 23.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(3.f, 2.f), sf::Vector2f(245.f, 23.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(3.f, 2.f), sf::Vector2f(264.f, 23.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(3.f, 2.f), sf::Vector2f(276.f, 23.f)));
	platformWithCollision.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(3.f, 2.f), sf::Vector2f(125.f, 29.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(2.f, 3.f), sf::Vector2f(45.f, 22.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 6.f), sf::Vector2f(0.f, 19.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(1.f, 6.f), sf::Vector2f(19.f, 19.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(5.f, 1.f), sf::Vector2f(47.f, 20.f)));
	platformWithCollision.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(5.f, 1.f), sf::Vector2f(173.f, 21.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(1.f, 5.f), sf::Vector2f(75.f, 11.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(4.f, 1.f), sf::Vector2f(42.f, 11.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(4.f, 1.f), sf::Vector2f(76.f, 11.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(4.f, 1.f), sf::Vector2f(46.f, 12.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(4.f, 1.f), sf::Vector2f(171.f, 19.f)));
	platformWithCollision.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(4.f, 1.f), sf::Vector2f(171.f, 20.f)));
	platformWithCollision.push_back(Platform(&(this->textures["IRON"]), sf::Vector2f(4.f, 1.f), sf::Vector2f(55.f, 24.f)));
	platformWithCollision.push_back(Platform(&(this->textures["IRON"]), sf::Vector2f(2.f, 2.f), sf::Vector2f(45.f, 20.f)));
	platformWithCollision.push_back(Platform(&(this->textures["IRON"]), sf::Vector2f(2.f, 2.f), sf::Vector2f(75.f, 20.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 4.f), sf::Vector2f(76.f, 12.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(1.f, 4.f), sf::Vector2f(15.f, 21.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(1.f, 4.f), sf::Vector2f(23.f, 21.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(3.f, 1.f), sf::Vector2f(46.f, 13.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(3.f, 1.f), sf::Vector2f(239.f, 17.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(3.f, 1.f), sf::Vector2f(270.f, 17.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(3.f, 1.f), sf::Vector2f(175.f, 20.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(3.f, 1.f), sf::Vector2f(178.f, 21.f)));
	platformWithCollision.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(3.f, 1.f), sf::Vector2f(178.f, 22.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(1.f, 3.f), sf::Vector2f(68.f, 12.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(1.f, 3.f), sf::Vector2f(68.f, 17.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(1.f, 3.f), sf::Vector2f(75.f, 17.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 3.f), sf::Vector2f(76.f, 17.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(50.f, 7.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(70.f, 7.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(50.f, 16.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(153.f, 19.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(53.f, 20.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(151.f, 20.f)));
	platformWithCollision.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(153.f, 20.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(149.f, 21.f)));
	platformWithCollision.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(151.f, 21.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["DIRT2"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(153.f, 21.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["DIRT2"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(171.f, 21.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(147.f, 22.f)));
	platformWithCollision.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(149.f, 22.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(234.f, 22.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(245.f, 22.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(265.f, 22.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(276.f, 22.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(55.f, 23.f)));
	platformWithCollision.push_back(Platform(&(this->textures["IRON"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(57.f, 23.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(122.f, 23.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(121.f, 24.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(120.f, 25.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["DIRT2"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(125.f, 25.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(127.f, 25.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(119.f, 26.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(126.f, 26.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["DIRT2"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(120.f, 27.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(125.f, 27.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(124.f, 28.f)));
	platformWithCollision.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(126.f, 28.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(2.f, 1.f), sf::Vector2f(123.f, 29.f)));
	platformWithCollision.push_back(Platform(&(this->textures["IRON"]), sf::Vector2f(1.f, 2.f), sf::Vector2f(53.f, 10.f)));
	platformWithCollision.push_back(Platform(&(this->textures["IRON"]), sf::Vector2f(1.f, 2.f), sf::Vector2f(68.f, 10.f)));
	platformWithCollision.push_back(Platform(&(this->textures["IRON"]), sf::Vector2f(1.f, 2.f), sf::Vector2f(68.f, 15.f)));
	platformWithCollision.push_back(Platform(&(this->textures["IRON"]), sf::Vector2f(1.f, 2.f), sf::Vector2f(68.f, 20.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(1.f, 2.f), sf::Vector2f(11.f, 23.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(1.f, 2.f), sf::Vector2f(27.f, 23.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["DIRT2"]), sf::Vector2f(1.f, 2.f), sf::Vector2f(96.f, 23.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["DIRT2"]), sf::Vector2f(1.f, 2.f), sf::Vector2f(106.f, 23.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 2.f), sf::Vector2f(112.f, 28.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(49.f, 4.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(72.f, 4.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(51.f, 5.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(70.f, 5.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(47.f, 6.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(51.f, 6.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(70.f, 6.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(74.f, 6.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(49.f, 7.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(72.f, 7.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(45.f, 8.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(76.f, 8.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(47.f, 9.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(48.f, 9.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(73.f, 9.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(74.f, 9.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(43.f, 10.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BLOCK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(78.f, 10.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["BRICK2"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(46.f, 11.f)));
	platformWithCollision.push_back(Platform(&(this->textures["IRON"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(49.f, 13.f)));
	platformWithCollision.push_back(Platform(&(this->textures["IRON"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(52.f, 16.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(240.f, 16.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(271.f, 16.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(237.f, 19.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(243.f, 19.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(268.f, 19.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(274.f, 19.f)));
	platformWithCollision.push_back(Platform(&(this->textures["IRON"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(52.f, 20.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(235.f, 21.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(245.f, 21.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(266.f, 21.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(276.f, 21.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(96.f, 22.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(106.f, 22.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(181.f, 22.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["DIRT2"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(145.f, 24.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["DIRT2"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(183.f, 24.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(192.f, 24.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(197.f, 24.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(216.f, 24.f)));
	platformWithCollision.push_back(Platform(&(this->textures["GRASS"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(221.f, 24.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(232.f, 24.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(248.f, 24.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(263.f, 24.f)));
	platformWithCollision.push_back(Platform(&(this->textures["BRICK"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(279.f, 24.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["DIRT2"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(121.f, 26.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["DIRT2"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(125.f, 26.f)));
	platformWithCollision.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(127.f, 27.f)));
	platformWithoutCollision.push_back(Platform(&(this->textures["DIRT2"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(123.f, 28.f)));
	platformWithCollision.push_back(Platform(&(this->textures["DIRT"]), sf::Vector2f(1.f, 1.f), sf::Vector2f(124.f, 30.f)));

	goal = new Goal(&(this->textures["GOAL"]), sf::Vector2f(GOAL_WIDTH, GOAL_HEIGHT), sf::Vector2f(284.f * UNIT_LENGTH, 22.f * UNIT_LENGTH));
}


void GameState_PalmBoulevard::initEntities()
{
	this->player = new Player(5.f, 24.f, this->textures["PLAYER_SHEET"], 200.f);
	
	nyanCats.push_back(new NyanCat(58.f, 10.f, this->textures["NYANCAT"], 20.f));
	nyanCats.push_back(new NyanCat(63.f, 10.f, this->textures["NYANCAT"], 20.f));
	wickedDoge.push_back(new WickedDoge(158.f, 17.f, this->textures["WICKED_DOGE"], 200.f));
	wickedDoge.push_back(new WickedDoge(169.f, 17.f, this->textures["WICKED_DOGE"], 200.f));
	maisies.push_back(new Maisy(237.f, 18.f, this->textures["MAISY"], 60.f));
	maisies.push_back(new Maisy(50.f, 19.f, this->textures["MAISY"], 60.f));
	wickedDoge.push_back(new WickedDoge(152.f, 19.f, this->textures["WICKED_DOGE"], 200.f));
	maisies.push_back(new Maisy(65.f, 20.f, this->textures["MAISY"], 60.f));
	bicycles.push_back(new Bicycle(102.f, 20.f, this->textures["BICYCLE"], 0.f));
	wickedDoge.push_back(new WickedDoge(245.f, 20.f, this->textures["WICKED_DOGE"], 200.f));
	maisies.push_back(new Maisy(265.f, 20.f, this->textures["MAISY"], 60.f));
	bicycles.push_back(new Bicycle(122.f, 21.f, this->textures["BICYCLE"], 0.f));
	nyanCats.push_back(new NyanCat(127.f, 21.f, this->textures["NYANCAT"], 20.f));
	maisies.push_back(new Maisy(147.f, 21.f, this->textures["MAISY"], 60.f));
	maisies.push_back(new Maisy(195.f, 22.f, this->textures["MAISY"], 60.f));
	wickedDoge.push_back(new WickedDoge(252.f, 23.f, this->textures["WICKED_DOGE"], 200.f));
	shuiYuanABes.push_back(new ShuiYuanABe(259.f, 23.f, this->textures["ABE"], 80.f));
	maisies.push_back(new Maisy(13.f, 24.f, this->textures["MAISY"], 60.f));
	maisies.push_back(new Maisy(17.f, 24.f, this->textures["MAISY"], 60.f));
	maisies.push_back(new Maisy(21.f, 24.f, this->textures["MAISY"], 60.f));
	maisies.push_back(new Maisy(25.f, 24.f, this->textures["MAISY"], 60.f));
	maisies.push_back(new Maisy(45.f, 24.f, this->textures["MAISY"], 60.f));
	wickedDoge.push_back(new WickedDoge(104.f, 24.f, this->textures["WICKED_DOGE"], 200.f));
	bicycles.push_back(new Bicycle(107.f, 24.f, this->textures["BICYCLE"], 0.f));
	bicycles.push_back(new Bicycle(115.f, 24.f, this->textures["BICYCLE"], 0.f));
	wickedDoge.push_back(new WickedDoge(142.f, 24.f, this->textures["WICKED_DOGE"], 200.f));
	maisies.push_back(new Maisy(149.f, 24.f, this->textures["MAISY"], 60.f));
	wickedDoge.push_back(new WickedDoge(163.f, 24.f, this->textures["WICKED_DOGE"], 200.f));
	maisies.push_back(new Maisy(179.f, 24.f, this->textures["MAISY"], 60.f));
	nyanCats.push_back(new NyanCat(205.f, 24.f, this->textures["NYANCAT"], 20.f));
	nyanCats.push_back(new NyanCat(210.f, 24.f, this->textures["NYANCAT"], 20.f));
	maisies.push_back(new Maisy(126.f, 25.f, this->textures["MAISY"], 60.f));
	maisies.push_back(new Maisy(122.f, 27.f, this->textures["MAISY"], 60.f));
	maisies.push_back(new Maisy(115.f, 29.f, this->textures["MAISY"], 60.f));
	maisies.push_back(new Maisy(119.f, 29.f, this->textures["MAISY"], 60.f));

	// set boss
	boss = shuiYuanABes[0];
}

GameState_PalmBoulevard::GameState_PalmBoulevard(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: GameState(window, supportedKeys, states)
{
	this->initPlatform();
	this->initEntities();

	this->initKeybinds();
	this->initFonts();
	this->initTexture();

	this->initGUI();
	this->initBackground();
	this->initPauseMenu();
	this->initGameoverState();
	this->initSuccessState();
}

GameState_PalmBoulevard::~GameState_PalmBoulevard()
{
}