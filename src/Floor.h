#include "raylib.h"

class Floor
{
public:
	Floor();

	void draw();

private:
	static constexpr Vector2 position = { 0.0f, 550.0f };
	static constexpr float Width = 800.0f;
	static constexpr float Height = 50.0f;
};