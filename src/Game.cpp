#include "Game.h"

Game::Game() {
	InitWindow(800, 600, "Platformer");
	SetTargetFPS(60);
	run();
}

void Game::run() {
	while (!WindowShouldClose())
	{
		float deltaTime = GetFrameTime();
		processInput(deltaTime);
		update(deltaTime);
		draw();
	}

	CloseWindow();
}

void Game::processInput(float deltaTime) {
	if (IsKeyPressed(KEY_SPACE) && playerFloorCollided)
	{
			player.jump();
	}

	if (IsKeyDown(KEY_D))
	{
		player.moveRight(deltaTime);
	}

	if (IsKeyDown(KEY_A))
	{
		player.moveLeft(deltaTime);
	}
}

void Game::update(float deltaTime) {
	player.update(deltaTime);

	if (CheckCollisionRecs(player.getCollisionRect(), floor.getCollisionRect()))
	{
		float floorPosY = floor.getCollisionRect().y;
		player.hitFloor(floorPosY);
		playerFloorCollided = true;
	}
	else
		playerFloorCollided = false;
}

void Game::draw() {
	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawText("Platformer", 300, 10, 30, BLACK);

	floor.draw();
	player.draw();
	EndDrawing();
}