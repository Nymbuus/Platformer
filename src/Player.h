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

	void update(float deltaTime);
	void draw();
	void reset();

	void jump();
	void moveRight(float deltaTime);
	void moveLeft(float deltaTime);
	void hitFloor(float stayPosY);

	Rectangle getCollisionRect() const;

private:
	Vector2 position;
	Vector2 velocity;

	static constexpr Vector2 InitVel = { 0.0f, 0.0f };
	static constexpr Vector2 InitPos = { 100.0f, 480.0f };
	static constexpr float JumpStrength = -500.0f;
	static constexpr float HorizontalAcceleration = 1000.0f;
	static constexpr float Width = 25.0f;
	static constexpr float Height = 50.0f;
	static constexpr float Gravity = 1000.0f;
};