#include "raylib.h"
#include "Floor.h"
#include "Platform.h"
#include "Player.h"
#include <vector>

class Game
{
public:
	Game();

	void run();

private:
	Floor floor;
	Player player;

	std::vector<Platform> platforms;
	bool jumpReady = false;
	float CollisionOffset = 5.0f;

	void processInput(float deltaTime);
	void update(float deltaTime);
	void draw();

	void createPlatforms();

	void checkPlatformCollision(
		Rectangle playerCollision,
		Rectangle previousPlayerCollision,
		Rectangle platformCollision);
};