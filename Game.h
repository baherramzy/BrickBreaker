#ifndef GAME_T
#define GAME_T

#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

class Game
{
private:
	sf::RenderWindow window{ sf::VideoMode(windowWidth, windowHeight), "Brick Breaker"}; // Window

	int lives{ 3 }; // Player lives

	// Ball variables
	Ball ball{ windowWidth / 2.0f, windowHeight / 2.0f };

	// Paddle variables
	Paddle paddle{ windowWidth / 2.0f, windowHeight - 50 };

	// Brick variables
	std::vector<Brick> bricks; // Vector of bricks

	int XBrickCount{ 12 }, YBrickCount{ 3 }; // Horizontal and vertical brick counts
	float XBrickSpacing{ 5.0f }; // Space between individual horizontal bricks
	float YBrickSpacing{ 7.0f }; // Space between individual vertical bricks
	float XBrickStartOffset{ Brick::width / 2.0f + 10.0f }; // Left side blank space
	float YBrickStartOffset{ Brick::height / 2.0f + 10.0f }; // Top side blank space

	// State variables
	enum class State { Win, GameOver, Paused, Running };
	State state{State::Paused};

	// Text variables
	sf::Text StateText;
	sf::Font Arial;
	float XTextOffset{ 120.0f }, YTextOffset{ 130.0f };

	void CenterText(sf::Text& t);
	void drawAllObjects();
	void updateAllObjects();
	void clearDestroyedBricks();

	template <class T1, class T2>
	bool CheckIntersection(T1&, T2&); // Generic intersection check

	void CheckObjectCollisions();
public:
	Game();
	void start();
	void run();
};

#endif