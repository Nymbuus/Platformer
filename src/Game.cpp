#include "Game.h"
#include <iostream>

Game::Game() {
	InitWindow(800, 600, "Platformer");
	SetTargetFPS(60);
	createPlatforms();
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
	if (IsKeyPressed(KEY_SPACE))
	{
		if (jumpReady)
		{
			player.jump();
		}
	}

	if (IsKeyDown(KEY_D))
	{
		player.moveRight(deltaTime);
	}
	else if (IsKeyDown(KEY_A))
	{
		player.moveLeft(deltaTime);
	}
	else
	{
		player.deaccelerate(deltaTime);
	}
}

void Game::update(float deltaTime) {
	jumpReady = false;
	Rectangle previousPlayerCollision = player.getCollisionRect();

	player.update(deltaTime);

	Rectangle playerCollision = player.getCollisionRect();
	Rectangle platformCollision = platforms.front().getCollisionRect();
	checkPlatformCollision(playerCollision, previousPlayerCollision, platformCollision);

	Rectangle floorColl = floor.getCollisionRect();

	// Checks if the player has collided with the floor.
	if (CheckCollisionRecs(playerCollision, floorColl))
	{
		float floorPosY = floorColl.y;
		player.hitVertical(floorPosY - playerCollision.height);
		jumpReady = true;
	}
}

void Game::draw() {
	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawText("Platformer", 300, 10, 30, BLACK);

	floor.draw();
	player.draw();
	if(!platforms.empty())
	{
		for (int i = 0; i < platforms.size(); i++)
			platforms.at(i).draw();
	}
	EndDrawing();
}

void Game::createPlatforms() {
	Platform platform({ 400.0f, 420.0f });
	platforms.emplace_back(platform);
}

void Game::checkPlatformCollision(
	Rectangle playerCollision,
	Rectangle previousPlayerCollision,
	Rectangle platformCollision) {
	if (CheckCollisionRecs(playerCollision, platformCollision))
	{
		float previousLeft = previousPlayerCollision.x;
		float previousRight = previousLeft + previousPlayerCollision.width;
		float previousTop = previousPlayerCollision.y;
		float previousBottom = previousTop + previousPlayerCollision.height;

		float playerLeft = playerCollision.x;
		float playerRight = playerLeft + playerCollision.width;
		float playerTop = playerCollision.y;
		float playerBottom = playerTop + playerCollision.height;

		float platformLeft = platformCollision.x;
		float platformRight = platformLeft + platformCollision.width;
		float platformTop = platformCollision.y;
		float platformBottom = platformTop + platformCollision.height;

		// Land on top of the platform
		if (previousBottom <= platformTop && playerBottom >= platformTop)
		{
			std::cout << "Sitting on the plat!" << std::endl;
			player.hitVertical(platformTop - playerCollision.height);
			jumpReady = true;
		}
		// Hit the underside of the platform
		else if (previousTop >= platformBottom && playerTop <= platformBottom)
		{
			player.hitVertical(platformBottom);
		}
		// Hit the left side of the platform
		else if (previousRight <= platformLeft && playerRight >= platformLeft)
		{
			player.hitWall(platformLeft - playerCollision.width);
		}
		// Hit the right side of the platform
		else if (previousLeft >= platformRight && playerLeft <= platformRight)
		{
			player.hitWall(platformRight);
		}
	}
}