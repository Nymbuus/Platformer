#include "Player.h"

Player::Player()
	: position{100.0f, 480.0f},
	  verticalSpeed{0.0f}
{
}

void Player::update() {

}

void Player::draw() {
	DrawRectangle(position.x, position.y, Width, Height, BLUE);
}