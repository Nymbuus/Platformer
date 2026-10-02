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

	void processInput();
	void update();
	void draw();
};