#include "Platform.h"

Platform::Platform(Vector2 position)
	: position(position)
{
}

void Platform::draw()
{
	DrawRectangle(position.x, position.y, Width, Height, RED);
}

Rectangle Platform::getCollisionRect() const
{
	return Rectangle(
		position.x,
		position.y,
		Width,
		Height
	);
}

float Platform::getRightSide() {
	return position.x + Width;
}

float Platform::getLeftSide() {
	return position.x;
}

float Platform::getBottomSide() {
	return position.y + Height;
}

float Platform::getTopSide() {
	return position.y;
}