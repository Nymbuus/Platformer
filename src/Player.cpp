#include "Player.h"

Player::Player()
	: position{InitPos},
	  velocity{InitVel}
{
}

void Player::update(float deltaTime) {
	velocity.y += Gravity * deltaTime;
	position.y += velocity.y * deltaTime;
}

void Player::draw() {
	DrawRectangle(position.x, position.y, Width, Height, BLUE);
}

void Player::reset() {
	position = InitPos;
	velocity = InitVel;
}

void Player::jump() {

}

Rectangle Player::getCollisionRect() const{
	return Rectangle(
		position.x,
		position.y,
		Width,
		Height
	);
}