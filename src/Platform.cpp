#include "Platform.h"

Platform::Platform(Vector2 position, float width, float height)
	: position(position),
	  playerHitLeft{false},
	  width{width},
	  height{height}
{
}

void Platform::draw()
{
	DrawRectangle(position.x, position.y, width, height, RED);
}

Rectangle Platform::getCollisionRect() const
{
	return Rectangle(
		position.x,
		position.y,
		width,
		height
	);
}

float Platform::getRightSide() {
	return position.x + width;
}

float Platform::getLeftSide() {
	return position.x;
}

float Platform::getBottomSide() {
	return position.y + height;
}

float Platform::getTopSide() {
	return position.y;
}

void Platform::hitLeft(bool hit) {
	playerHitLeft = hit;
}

bool Platform::hasPlayerHitLeft() {
	return playerHitLeft;
}