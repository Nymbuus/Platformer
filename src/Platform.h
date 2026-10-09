#include "raylib.h"

class Platform
{
public:
	Platform(Vector2 position);

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

	static constexpr float Width = 100.0f;
	static constexpr float Height = 50.0f;
};