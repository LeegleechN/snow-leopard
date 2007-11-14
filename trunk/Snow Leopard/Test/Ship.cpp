#include "Ship.h"


bool Ship::doActions()
{

	move();
	shoot();
	return true;
	
}

bool Ship::move()
{
	return true;
}

bool Ship::move(AbsoluteDirection dir)
{
	if (dir == UP)
		worldState->moveObject(this,location.offsetRect(0,-speed));
	if (dir == DOWN)
		worldState->moveObject(this,location.offsetRect(0,speed));
	if (dir == LEFT)
		worldState->moveObject(this,location.offsetRect(-speed,0));
	if (dir == RIGHT)
		worldState->moveObject(this,location.offsetRect(speed,0));

	return true;
}

bool Ship::move(RelativeDirection dir)
{
	if (dir == FORWARD)
		worldState->moveObject(this,location.offsetPolar(heading,-speed));
	if (dir == BACK)
		worldState->moveObject(this,location.offsetPolar(heading,speed));
	if (dir == TURN_LEFT)
		heading -= 1;
	if (dir == TURN_RIGHT)
		heading += 1;

	return true;
}

bool Ship::shoot()
{
	return true;
}

Ship::Ship(std::string resourceName,CL_ResourceManager* resources) : GameObject(resourceName,resources)
{
	actionPriority = ShipActionPriority;
	renderPriority = ShipRenderPriority;
}
	
bool Ship::registerWallCollision()
{
	return true; //if you hit a wall, don't di anything
}