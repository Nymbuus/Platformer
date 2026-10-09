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
	if (IsKeyPressed(KEY_SPACE) && playerFloorCollided)
	{
			player.jump();
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
	player.update(deltaTime);
	Rectangle playerCollision = player.getCollisionRect();
	float playerRight = player.getRightSide();
	float playerLeft = player.getLeftSide();
	float playerBottom = player.getBottomSide();
	float playerTop = player.getTopSide();
	Rectangle platformCollision = platforms.front().getCollisionRect();
	float platformRight = platforms.front().getRightSide();
	float platformLeft = platforms.front().getLeftSide();
	float platformBottom = platforms.front().getBottomSide();
	float platformTop = platforms.front().getTopSide();

	if (CheckCollisionRecs(playerCollision, platformCollision))
	{
		if (playerBottom - CollisionOffset > platformTop &&
			playerTop + CollisionOffset < platformBottom &&
			playerLeft < platformLeft &&
			playerCollision.width > platformLeft - playerLeft)
		{
			std::cout << "platform!!  Hit Left Wall" << std::endl;
			player.hitWall(platformLeft - playerCollision.width);
		}

		if (playerBottom - CollisionOffset > platformTop &&
			playerTop + CollisionOffset < platformBottom &&
			playerRight > platformRight &&
			playerCollision.width > playerRight - platformRight)
		{
			std::cout << "platform!! Hit Right Wall" << std::endl;
			player.hitWall(platformRight);
		}

		if (playerRight - CollisionOffset > platformLeft &&
			playerLeft + CollisionOffset < platformRight &&
			playerTop < platformTop &&
			playerCollision.height > platformTop - playerTop)
		{
			std::cout << "platform!!  Hit Floor" << std::endl;
			player.hitVertical(platformTop - playerCollision.height);
		}

		if (playerRight - CollisionOffset > platformLeft &&
			playerLeft + CollisionOffset < platformRight &&
			playerTop > platformTop &&
			playerCollision.height > playerBottom - platformBottom)
		{
			std::cout << "platform!!  Hit Roof" << std::endl;
			player.hitVertical(platformBottom);
		}
	}

	Rectangle floorCollision = floor.getCollisionRect();

	if (CheckCollisionRecs(playerCollision, floorCollision))
	{
		float floorPosY = floorCollision.y;
		player.hitVertical(floorPosY - playerCollision.height);
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