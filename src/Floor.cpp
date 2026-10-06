#include "Floor.h"

Floor::Floor()
{
}

void Floor::draw()
{
	DrawRectangle(position.x, position.y, Width, Height, GREEN);
}

Rectangle Floor::getCollisionRect() const{
	return Rectangle(
		position.x,
		position.y,
		Width,
		Height
	);
}