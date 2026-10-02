#include "raylib.h"

enum class Direction
{
	West,
	East
};

class Player
{
public:
	Player();

	void update();
	void draw();
	void reset();

	void jump();

private:
	Vector2 position;
	float verticalSpeed;

	static constexpr float JumpSpeed = -500.0f;
	static constexpr float Width = 25.0f;
	static constexpr float Height = 50.0f;
	static constexpr float Gravity = 1000.0f;
};