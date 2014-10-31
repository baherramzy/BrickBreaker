// Global variables visible to all objects
#ifndef GLOBAL_T
#define GLOBAL_T
static const int windowWidth = 800, windowHeight = 600;
#endif

/* The Entity class is the main base class for drawable objects
 and is an abstract class, i.e. cannot be instantiated
 (Note: This means that derived classes MUST define update() and draw()
 in order not to become abstract classes themselves) */

#ifndef ENTITY_T
#define ENTITY_T

#include <SFML\Graphics.hpp>

class Entity
{
public:
	virtual void update() = 0; // Called every frame
	virtual void draw(sf::RenderWindow& targetWindow) = 0;
	virtual ~Entity() {}
};

#endif