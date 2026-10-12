#include "raylib.h"

class Platform
{
public:
	Platform(Vector2 position, float width, float height);

	void draw();
	
	Rectangle getCollisionRect() const;

	float getRightSide();
	float getLeftSide();
	float getBottomSide();
	float getTopSide();

	void hitLeft(bool hit);
	bool hasPlayerHitLeft();

private:
	Vector2 position;

	bool playerHitLeft;

	float width;
	float height;
};