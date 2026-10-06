#include "raylib.h"
#include "Floor.h"
#include "Player.h"

class Game
{
public:
	Game();

	void run();

private:
	Floor floor;
	Player player;

	bool playerFloorCollided = false;

	void processInput(float deltaTime);
	void update(float deltaTime);
	void draw();
};