#include "Game.h"

Game::Game() {
	InitWindow(800, 600, "Platformer");
	SetTargetFPS(60);
	run();
}

void Game::run() {
	while (!WindowShouldClose())
	{
		processInput();
		update();
		draw();
	}

	CloseWindow();
}

void Game::processInput() {

}

void Game::update() {
	player.update();
}

void Game::draw() {
	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawText("Platformer", 300, 10, 30, BLACK);

	floor.draw();
	player.draw();
	EndDrawing();
}