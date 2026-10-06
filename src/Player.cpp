#include "Player.h"
#include <iostream>

Player::Player()
	: position{InitPos},
	  velocity{InitVel}
{
}

void Player::update(float deltaTime) {
	velocity.y += Gravity * deltaTime;
	position.y += velocity.y * deltaTime;

	if (!IsKeyDown(KEY_D) && !IsKeyDown(KEY_A)) {
		if (velocity.x > 20.0f)
			velocity.x -= HorizontalAcceleration * deltaTime;
		else if (velocity.x < -20.0f) {
			std::cout << "PLUS!!!!  VelocityX: " << velocity.x << std::endl;
			velocity.x += HorizontalAcceleration * deltaTime;
		}
		else
		{
			std::cout << "VelocityX: " << velocity.x << std::endl;
			velocity.x = 0.0f;
		}
	}
	position.x += velocity.x * deltaTime;
}

void Player::draw() {
	DrawRectangle(position.x, position.y, Width, Height, BLUE);
}

void Player::reset() {
	position = InitPos;
	velocity = InitVel;
}

void Player::jump() {
	velocity.y = JumpStrength;
}

void Player::moveRight(float deltaTime) {
	velocity.x += HorizontalAcceleration * deltaTime;
}

void Player::moveLeft(float deltaTime) {
	velocity.x -= HorizontalAcceleration * deltaTime;
}

void Player::hitFloor(float stayPosY) {
	position.y = stayPosY - Height;
	velocity.y = 0.0f;
}

Rectangle Player::getCollisionRect() const{
	return Rectangle(
		position.x,
		position.y,
		Width,
		Height
	);
}