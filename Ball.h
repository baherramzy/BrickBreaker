#ifndef BALL_T
#define BALL_T

#include "Entity.h"
#include "Circle.h"

class Ball : public Entity, public Circle
{
private:
	void CheckWallCollisions();
public:
	sf::Color color = sf::Color::White; // Color
	static const float radius; // Radius
	const float speed{ 8.0f }; // Ball movement speed
	sf::Vector2f velocity{ speed, speed }; // Ball velocity vector, initialized to speed values
	bool Loss{ false };
	float StartX, StartY; // Initial starting co-ordinates, for resetting the ball

	Ball(float x, float y);
	void Reinitialize();
	void update() override;
	void draw(sf::RenderWindow& targetWindow) override;
};

#endif