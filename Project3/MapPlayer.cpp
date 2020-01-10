#include "MapPlayer.h"


MapPlayer::MapPlayer(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime, IDLE_WIDTH, IDLE_HEIGHT, WALKING_WIDTH, WALKING_HEIGHT, JUMPING_WIDTH, JUMPING_HEIGHT)
{
	this->checkpoint[0] = new sf::Vector2f(594.f, 757.f);
	this->checkpoint[1] = new sf::Vector2f(594.f, 382.f);
	this->checkpoint[2] = new sf::Vector2f(594.f, 38.f);
	this->checkpoint[3] = new sf::Vector2f(939.f, 38.f);
	this->checkpoint[4] = new sf::Vector2f(1245.f, 38.f);
	this->checkpoint[5] = new sf::Vector2f(1245.f, 338.f);
	this->checkpoint[6] = new sf::Vector2f(1245.f, 618.f);
	this->checkpoint[7] = new sf::Vector2f(822.f, 618.f);
	this->checkpoint[8] = new sf::Vector2f(822.f, 915.f);

	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(150.0f, 150.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(this->checkpoint[0]->x, this->checkpoint[0]->y);
	body.setTexture(texture);

	destCheckpoint.x = this->checkpoint[1]->x;
	destCheckpoint.y = this->checkpoint[1]->y;
	judgeMove = true;
	keyNeedToBe = sf::Keyboard::Up;
	havePressedEnter = false;
	canGo = false;
}

MapPlayer::~MapPlayer()
{
	for (int i = 0; i < 9; i++) {
		delete checkpoint[i];
	}
}

void MapPlayer::update(float deltaTime, sf::Keyboard::Key keyPressed, bool isPressed, bool canGo)
{
	sf::Vector2f movement(0.0f, 0.0f);

	//printf("%f\n%f\n", destCheckpoint.x, destCheckpoint.y);
	printf("%f\n%f\n", this->body.getPosition().x, this->body.getPosition().y);

	if (keyPressed == sf::Keyboard::Enter) {
		havePressedEnter = true;
	}

	if (isPressed == true && canGo == true && (abs(this->body.getPosition().x - destCheckpoint.x) < DIS && abs(this->body.getPosition().y - destCheckpoint.y) < DIS)) {
		havePressedEnter = true;
		//std::cout << "kjhgfffffffffffffffffff" << "\n";
	}

	if ((abs(this->body.getPosition().x - this->checkpoint[4]->x) < DIS && abs(this->body.getPosition().y - this->checkpoint[4]->y) < DIS) /*|| (abs(this->body.getPosition().x - 832.9f) < DIS && abs(this->body.getPosition().y - 475.2f) < DIS)*/) {
		searchDestinationCheckpoint(keyPressed);
	}

	judgeMove = move(keyPressed, isPressed);

	if (judgeMove && ((abs(body.getPosition().x - destCheckpoint.x) > DIS) || (abs(body.getPosition().y - destCheckpoint.y) > DIS))) {
		if (keyPressed == sf::Keyboard::Left)
			movement.x -= speed * deltaTime;
		if (keyPressed == sf::Keyboard::Right)
			movement.x += speed * deltaTime;
		if (keyPressed == sf::Keyboard::Down)
			movement.y += speed * deltaTime;
		if (keyPressed == sf::Keyboard::Up)
			movement.y -= speed * deltaTime;
	}

	if (movement.x == 0.0f && movement.y == 0.0f)
		row = 0;
	else {
		row = 1;

		if (movement.x >= 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}

	animation.update(row, deltaTime, faceRight, 0, sf::Vector2f(0.f, 0.f));
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void MapPlayer::draw(sf::RenderTarget* target)
{
	target->draw(this->body);
}

void MapPlayer::searchDestinationCheckpoint(sf::Keyboard::Key keyPressed) {
	if (keyPressed == sf::Keyboard::Up && (abs(this->body.getPosition().x - this->checkpoint[1]->x) < DIS && abs(this->body.getPosition().y - this->checkpoint[1]->y) < DIS)) {
		destCheckpoint.x = this->checkpoint[2]->x;
		destCheckpoint.y = this->checkpoint[2]->y;
		keyNeedToBe = sf::Keyboard::Up;
		havePressedEnter = false;
	}
	/*else if (keyPressed == sf::Keyboard::Right && (abs(this->body.getPosition().x - 530.f) < DIS && abs(this->body.getPosition().y - 475.2f) < DIS)) {
	destCheckpoint.x = 832.9f;
	destCheckpoint.y = 475.2f;
	keyNeedToBe = sf::Keyboard::Right;
	havePressedEnter = false;
	}
	else if (keyPressed == sf::Keyboard::Left && (abs(this->body.getPosition().x - 832.9f) < DIS && abs(this->body.getPosition().y - 475.2f) < DIS)) {
	destCheckpoint.x = 530.f;
	destCheckpoint.y = 475.2f;
	keyNeedToBe = sf::Keyboard::Left;
	havePressedEnter = false;
	}
	else if (keyPressed == sf::Keyboard::Down && (abs(this->body.getPosition().x - 832.9f) < DIS && abs(this->body.getPosition().y - 475.2f) < DIS)) {
	destCheckpoint.x = 832.9f;
	destCheckpoint.y = 670.f;
	keyNeedToBe = sf::Keyboard::Down;
	havePressedEnter = false;
	}
	else if (keyPressed == sf::Keyboard::Up && (abs(this->body.getPosition().x - 832.9f) < DIS && abs(this->body.getPosition().y - 670.f) < DIS)) {
	destCheckpoint.x = 832.9f;
	destCheckpoint.y = 475.2f;
	keyNeedToBe = sf::Keyboard::Up;
	havePressedEnter = false;
	}*/
	else if (keyPressed == sf::Keyboard::Right && (abs(this->body.getPosition().x - this->checkpoint[2]->x) < DIS && abs(this->body.getPosition().y - this->checkpoint[2]->y) < DIS)) {
		destCheckpoint.x = this->checkpoint[3]->x;
		destCheckpoint.y = this->checkpoint[3]->y;
		keyNeedToBe = sf::Keyboard::Right;
		havePressedEnter = false;
	}
	else if (keyPressed == sf::Keyboard::Down && (abs(this->body.getPosition().x - this->checkpoint[2]->x) < DIS && abs(this->body.getPosition().y - this->checkpoint[2]->y) < DIS)) {
		destCheckpoint.x = this->checkpoint[1]->x;
		destCheckpoint.y = this->checkpoint[1]->y;
		keyNeedToBe = sf::Keyboard::Down;
		havePressedEnter = false;
	}
	else if (keyPressed == sf::Keyboard::Right && (abs(this->body.getPosition().x - this->checkpoint[3]->x) < DIS && abs(this->body.getPosition().y - this->checkpoint[3]->y) < DIS)) {
		destCheckpoint.x = this->checkpoint[4]->x;
		destCheckpoint.y = this->checkpoint[4]->y;
		keyNeedToBe = sf::Keyboard::Right;
		havePressedEnter = false;
	}
	else if (keyPressed == sf::Keyboard::Left && (abs(this->body.getPosition().x - this->checkpoint[3]->x) < DIS && abs(this->body.getPosition().y - this->checkpoint[3]->y) < DIS)) {
		destCheckpoint.x = this->checkpoint[2]->x;
		destCheckpoint.y = this->checkpoint[2]->y;
		keyNeedToBe = sf::Keyboard::Left;
		havePressedEnter = false;
	}
	else if (keyPressed == sf::Keyboard::Down && (abs(this->body.getPosition().x - this->checkpoint[4]->x) < DIS && abs(this->body.getPosition().y - this->checkpoint[4]->y) < DIS)) {
		destCheckpoint.x = this->checkpoint[5]->x;
		destCheckpoint.y = this->checkpoint[5]->y;
		keyNeedToBe = sf::Keyboard::Down;
		havePressedEnter = false;
	}
	else if (keyPressed == sf::Keyboard::Left && (abs(this->body.getPosition().x - this->checkpoint[4]->x) < DIS && abs(this->body.getPosition().y - this->checkpoint[4]->y) < DIS)) {
		destCheckpoint.x = this->checkpoint[3]->x;
		destCheckpoint.y = this->checkpoint[3]->y;
		keyNeedToBe = sf::Keyboard::Left;
		havePressedEnter = false;
	}
	else if (keyPressed == sf::Keyboard::Down && (abs(this->body.getPosition().x - this->checkpoint[5]->x) < DIS && abs(this->body.getPosition().y - this->checkpoint[5]->y) < DIS)) {
		destCheckpoint.x = this->checkpoint[6]->x;
		destCheckpoint.y = this->checkpoint[6]->y;
		keyNeedToBe = sf::Keyboard::Down;
		havePressedEnter = false;
	}
	else if (keyPressed == sf::Keyboard::Up && (abs(this->body.getPosition().x - this->checkpoint[5]->x) < DIS && abs(this->body.getPosition().y - this->checkpoint[5]->y) < DIS)) {
		destCheckpoint.x = this->checkpoint[4]->x;
		destCheckpoint.y = this->checkpoint[4]->y;
		keyNeedToBe = sf::Keyboard::Up;
		havePressedEnter = false;
	}
	else if (keyPressed == sf::Keyboard::Left && (abs(this->body.getPosition().x - this->checkpoint[6]->x) < DIS && abs(this->body.getPosition().y - this->checkpoint[6]->y) < DIS)) {
		destCheckpoint.x = this->checkpoint[7]->x;
		destCheckpoint.y = this->checkpoint[7]->y;
		keyNeedToBe = sf::Keyboard::Left;
		havePressedEnter = false;
	}
	else if (keyPressed == sf::Keyboard::Up && (abs(this->body.getPosition().x - this->checkpoint[6]->x) < DIS && abs(this->body.getPosition().y - this->checkpoint[6]->y) < DIS)) {
		destCheckpoint.x = this->checkpoint[5]->x;
		destCheckpoint.y = this->checkpoint[5]->y;
		keyNeedToBe = sf::Keyboard::Up;
		havePressedEnter = false;
	}
	else if (keyPressed == sf::Keyboard::Down && (abs(this->body.getPosition().x - this->checkpoint[7]->x) < DIS) && (abs(this->body.getPosition().y - this->checkpoint[7]->y) < DIS)) {
		destCheckpoint.x = this->checkpoint[8]->x;
		destCheckpoint.y = this->checkpoint[8]->y;
		keyNeedToBe = sf::Keyboard::Down;
		havePressedEnter = false;
	}
	else if (keyPressed == sf::Keyboard::Right && (abs(this->body.getPosition().x - this->checkpoint[7]->x) < DIS) && (abs(this->body.getPosition().y - this->checkpoint[7]->y) < DIS)) {
		destCheckpoint.x = this->checkpoint[6]->x;
		destCheckpoint.y = this->checkpoint[6]->y;
		keyNeedToBe = sf::Keyboard::Right;
		havePressedEnter = false;
	}
	else if (keyPressed == sf::Keyboard::Up && (abs(this->body.getPosition().x - this->checkpoint[8]->x) < DIS) && (abs(this->body.getPosition().y - this->checkpoint[8]->y) < DIS)) {
		destCheckpoint.x = this->checkpoint[7]->x;
		destCheckpoint.y = this->checkpoint[7]->y;
		keyNeedToBe = sf::Keyboard::Up;
		havePressedEnter = false;
	}
}

bool MapPlayer::move(sf::Keyboard::Key keyPressed, bool isPressed)
{
	if ((abs(this->body.getPosition().x - destCheckpoint.x) < DIS && abs(this->body.getPosition().y - destCheckpoint.y) < DIS)) {
		if (havePressedEnter == true) {
			searchDestinationCheckpoint(keyPressed);
		}
	}

	if (isPressed == false || keyNeedToBe != keyPressed) {
		return false;
	}

	return true;
}