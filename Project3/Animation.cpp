#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,
	const unsigned int idleWidth,
	const unsigned int idleHeight,
	const unsigned int walkingWidth,
	const unsigned int walkingHeight,
	const unsigned int jumpingWidth,
	const unsigned int jumpingHeight) {
	//passes the imageCount to the imageCount in the class : animation
	this->imageCount = imageCount;
	//passes the switchTime to the switchTime in the class :¡@animation
	this->switchTime = switchTime;
	//initialize the total time passed
	this->totalTime = 0.f;
	//start from the first picture
	this->currentImage.x = 0;

	playedOnce = false;

	this->idleWidth = idleWidth;
	this->idleHeight = idleHeight;
	this->walkingWidth = walkingWidth;
	this->walkingHeight = walkingHeight;
	this->jumpingWidth = jumpingWidth;
	this->jumpingHeight = jumpingHeight;

	this->uvRect.width = idleWidth;
	this->uvRect.height = idleHeight;
	this->uvRect.top = 0;
	this->uvRect.left = 0;
	//this tells us how big each image should be(default is the size of idle animation)
}

void Animation::update(int row, float deltaTime, bool faceRight, float jumpHeight, sf::Vector2f velocity)
{
	if (row == 0 || row == 1) {
		if (row == 0) {
			this->uvRect.width = idleWidth;
			this->uvRect.height = idleHeight;
			this->uvRect.top = 0;
		}
		else if (row == 1) {
			this->uvRect.width = walkingWidth;
			this->uvRect.height = walkingHeight;
			this->uvRect.top = idleHeight;
		}
		//row determines which animation it is running
		this->currentImage.y = row;
		//add the time passed to total time
		this->totalTime += deltaTime;
		//if the time passed is greater than how long you want to display a picture
		if (this->totalTime >= this->switchTime) {
			//this is almost equivalent to totalTime = 0 but will leave the tiny bit of time, making the animation smoother in general
			this->totalTime = 0;
			//switch to the next picture(same row next column)
			this->currentImage.x++;
			//if surpass the number of pictures we have that row
			if (this->currentImage.x >= this->imageCount.x) {
				//back to picture 1
				this->currentImage.x = 0;
				this->playedOnce = true;
			}
		}
	}
	else if (row == 2) {
		if (this->currentImage.y != row) {
			this->totalTime = 0;
			this->currentImage.y = row;
			this->uvRect.top = idleHeight + walkingHeight;
			this->uvRect.width = jumpingWidth;
			this->uvRect.height = jumpingHeight;
		}
		float maxYVelocity = sqrt(2 * GRAVITY * jumpHeight);
		if (velocity.y < -maxYVelocity / 1.5f) {
			this->currentImage.x = 0;
		}
		else if (velocity.y <= 0) {
			this->currentImage.x = 1;
		}
		else if (velocity.y <= maxYVelocity / 1.5f) {
			this->currentImage.x = 2;
		}
		else {
			this->currentImage.x = 3;
		}
	}
	if (faceRight) {
		//make the width positive(making sure the image is not flipped and the display range is correct)
		this->uvRect.width = abs(this->uvRect.width);
		//the left location of the display in the texture pack is located at the column * width_per_image pixel
		this->uvRect.left = (this->currentImage.x) * this->uvRect.width;
	}
	//if the picture is facing the left side
	else {
		//flip the image
		this->uvRect.width = -abs(this->uvRect.width);
		//let the display be located at the top right corner of the image
		this->uvRect.left = (this->currentImage.x + 1) * abs(this->uvRect.width);
	}
}