#ifndef WEAPON_H_
#define WEAPON_H_
#include "Component.h"
#include "xerces.h"
#include "point.h"

class WorldState;

class Weapon:public Component
{
	public:
		const int coolDownInterval;
		void activate(WorldState* state,point location)
		{
			fire(state,location);
		}
		virtual void fire(WorldState* state, point location)
		{};
		unsigned int timeLastFired;
		Weapon::Weapon();
};

#endif