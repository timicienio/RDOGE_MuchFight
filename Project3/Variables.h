#pragma once

static const float VIEW_WIDTH = 1920.f;
static const float VIEW_HEIGHT = 1080.f;

static const float PLAYER_WIDTH = 50.f * 2;
static const float PLAYER_HEIGHT = 50.f * 2;

static const float UNIT_LENGTH = 50.f;

static const unsigned int IDLE_WIDTH = 49;
static const unsigned int IDLE_HEIGHT = 45;
static const unsigned int WALKING_WIDTH = 49;
static const unsigned int WALKING_HEIGHT = 45;
static const unsigned int JUMPING_WIDTH = 49;
static const unsigned int JUMPING_HEIGHT = 45;

static const float BICYCLE_WIDTH = 62.f * 2.5;
static const float BICYCLE_HEIGHT = 37.f * 2.5;

//Bicycle texture information
static const unsigned int BIKE_IDLE_WIDTH = 62;
static const unsigned int BIKE_IDLE_HEIGHT = 37;

static const float MAISY_WIDTH = 20.f * 2;
static const float MAISY_HEIGHT = 15.f * 2;

static const unsigned int MAISY_IDLE_HEIGHT = 10;
static const unsigned int MAISY_IDLE_WIDTH = 18;
static const unsigned int MAISY_WALKING_HEIGHT = 14;
static const unsigned int MAISY_WALKING_WIDTH = 19;
static const unsigned int MAISY_JUMPING_HEIGHT = 14;
static const unsigned int MAISY_JUMPING_WIDTH = 19;

static const float NYANCAT_WIDTH = 44.f * 3;
static const float NYANCAT_HEIGHT = 21.f * 3;

//Nyancat texture information
static const unsigned int NYANCAT_IDLE_WIDTH = 44;
static const unsigned int NYANCAT_IDLE_HEIGHT = 21;

static const float SHUIYUANABE_WIDTH = 40 * 3;
static const float SHUIYUANABE_HEIGHT = 60 * 3;

static const unsigned int SHUIYUANABE_IDLE_WIDTH = 39;
static const unsigned int SHUIYUANABE_IDLE_HEIGHT = 59;
static const unsigned int SHUIYUANABE_WALKING_WIDTH = 40;
static const unsigned int SHUIYUANABE_WALKING_HEIGHT = 59;
static const unsigned int SHUIYUANABE_JUMPING_WIDTH = 39;
static const unsigned int SHUIYUANABE_JUMPING_HEIGHT = 61;

static const unsigned int FIREBALL_WIDTH = 47;
static const unsigned int FIREBALL_HEIGHT = 20;

static const float THROWABLE_WIDTH = 47 * 1.5f;
static const float THROWABLE_HEIGHT = 20 * 1.5f;

static const float GRAVITY = 981.f;
static const float MAX_DROP_SPEED = 1000.f;

static const float KNOCKBACK_VELOCITY = 8000.f;
static const float KNOCKBACK_VELOCITY_VERTICAL = 1200.f;

static const float GOAL_WIDTH = 30.f * 3;
static const float GOAL_HEIGHT = 50.f * 3;

static const unsigned int GOAL_IDLE_WIDTH = 30;
static const unsigned int GOAL_IDLE_HEIGHT = 46;
static const unsigned int GOAL_MOVING_WIDTH = 30;
static const unsigned int GOAL_MOVING_HEIGHT = 46;


static const int MAISY_SCORE = 500;
static const int BICYCLE_SCORE = 1500;
static const int NYANCAT_SCORE = 4000;
static const int WICKED_DOGE_SCORE = 2000;
static const int SHUIYUANABE_SCORE = 10000;

static const int HEART_BONUS = 2500;
static const int TIME_DEDUCTION = 10;

// map
static const float DIS = 6.f;

enum entityAction {
	wanderingLeft,
	wanderingRight,
	idle,
	chasing
};

typedef enum entityAction EntityActionStatus;

enum entityAgression {
	rest,
	light,
	heavy,
	allOut
};

typedef enum entityAgression EntityAgressionStatus;