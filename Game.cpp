#include "Game.h"

Game::Game()
{
	window.setFramerateLimit(60);

	Arial.loadFromFile("arial.ttf");
	StateText.setFont(Arial);
	StateText.setCharacterSize(30);
	StateText.setPosition(windowWidth / 2.0f - 120.0f, windowHeight / 2.0f - 130.0f);
	StateText.setString("Press SPACE to begin");
	StateText.setColor(sf::Color::White);
}

void Game::start() {
	for (int i = 0; i < XBrickCount; ++i) {
		for (int j = 0; j < YBrickCount; ++j) {
			float x = i * (Brick::width + XBrickSpacing);
			float y = j * (Brick::height + YBrickSpacing);
			bricks.emplace_back(XBrickStartOffset + x, YBrickStartOffset + y);
		}
	}
}

template <class T1, class T2>
bool Game::CheckIntersection(T1& A, T2& B) {
	return	A.getLeft() <= B.getRight() &&
		B.getLeft() <= A.getRight() &&
		A.getTop() <= B.getBottom() &&
		B.getTop() <= A.getBottom();
}

void Game::CheckObjectCollisions() {
	// Check ball with paddle
	if (CheckIntersection(ball, paddle)) {
		ball.velocity.y = -ball.velocity.y; // Send ball flying upwards

		// Change x direction depending on which half of the paddle was hit
		ball.velocity.x = ball.getX() > paddle.getX() ? ball.speed : -ball.speed;
	}

	else {
		for (Brick& b : bricks) {
			if (CheckIntersection(ball, b)) {
				b.destroyed = true;

				// EXTENSIVE COLLISION CHECKING FOR ALL SIDES
				if (ball.getTop() <= b.getBottom() &&
					ball.getX() >= b.getLeft() && ball.getX() <= b.getRight()) { // brick bottom
					ball.velocity.y = -ball.velocity.y; // Send ball flying downwards 
				}
				else if (b.getTop() <= ball.getBottom() &&
					ball.getX() >= b.getLeft() && ball.getX() <= b.getRight()) { // brick top
					ball.velocity.y = -ball.velocity.y; // Send ball flying upwards
				}
				else if (ball.getLeft() <= b.getRight() &&
					ball.getY() >= b.getTop() && ball.getY() <= b.getBottom()) { // brick right
					ball.velocity.x = -ball.velocity.x; // Send ball flying right
				}
				else if (b.getLeft() <= ball.getRight() &&
					ball.getY() >= b.getTop() && ball.getY() <= b.getBottom()) { // brick left
					ball.velocity.x = -ball.velocity.x; // Send ball flying left
				}
			}
		}
	}
}

void Game::clearDestroyedBricks() {
	std::remove_if(std::begin(bricks), std::end(bricks),
		[](Brick& brick){return brick.destroyed; });
}

void Game::updateAllObjects() {
	if (state == State::Running) {
		// Update paddle
		paddle.update();

		// Update ball
		ball.update();

		// Check loss
		if (ball.Loss) {
			state = State::GameOver;
			StateText.setString("Game over");
		}
	}
}

void Game::drawAllObjects() {
	// Draw paddle
	paddle.draw(window);

	// Draw ball
	ball.draw(window);

	// Draw text
	if (state != State::Running)
		window.draw(StateText);

	// Draw bricks
	for (Brick& b : bricks) {
		if (!b.destroyed)
			b.draw(window);
	}
}
void Game::run() {
	while (window.isOpen()) {
		window.clear(sf::Color::Black);

		sf::Event event;

		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::P) {
					if (state == State::Running) { 
						state = State::Paused; 
						StateText.setPosition(windowWidth / 2.0f - 50.0f, windowHeight / 2.0f - 130.0f);
						StateText.setString("Paused"); 
					}
					else if (state == State::Paused) state = State::Running;
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		updateAllObjects();

		CheckObjectCollisions();

		drawAllObjects();

		clearDestroyedBricks();


		window.display();
	}
}

Game::~Game()
{
}