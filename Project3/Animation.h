#pragma once
#include<SFML\Graphics.hpp>
#include"MovementComponent.h"

class Animation
{
public:
	//constructor passes in (texture pack, total images(x,y), switch time)
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,
		const unsigned int idleWidth,
		const unsigned int idleHeight,
		const unsigned int walkingWidth,
		const unsigned int walkingHeight,
		const unsigned int jumpingWidth,
		const unsigned int jumpingHeight);
	//all the width and height of each animation row
	//if you want more animations, add them to private and initalize them here

	//function for updating the player status
	void update(int row, float deltaTime, bool faceRight, float jumpHeight, sf::Vector2f velocity);
	float getTotalTime() { return totalTime; }

	void setImageCount(sf::Vector2u imageCount) { 
		this->imageCount.x = imageCount.x;
		this->imageCount.y = imageCount.y;
	}
public:
	bool playedOnce;
	//the current display in the texture
	sf::IntRect uvRect;

private:
	//how many images to go through
	sf::Vector2u imageCount;
	//a vector2u to store the current image, (row, column)
	sf::Vector2u currentImage;
	//the total time needed to iterate through the images
	float totalTime;
	//the time that every image is displayed
	float switchTime;

	unsigned int idleWidth;
	unsigned int idleHeight;
	unsigned int walkingWidth;
	unsigned int walkingHeight;
	unsigned int jumpingWidth;
	unsigned int jumpingHeight;
};


