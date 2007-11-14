#include "WorldState.h"
#include "GameObject.h"

//need to have a method that returns only what locations of objects changed during the last step,
//so the openGL renderer can translate efficiently

inline int round(double x)
{
return int(x > 0.0 ? x + 0.5 : x - 0.5);
}

WorldState::WorldState()
{
	CoordinateSizeX = 1024.0;
	CoordinateSizeY = 768.0;

	CellSizeX = (int)CoordinateSizeX / coarseGraining ;
	CellSizeY = (int)CoordinateSizeY / coarseGraining ;

	allObjectList = new GameObjectList();
	worldMatrix = new GameObjectList**[CellSizeX];
	for (int i = 0; i < CellSizeX; ++i)
        worldMatrix[i] = new GameObjectList*[CellSizeY];

	for (int i=0;i<CellSizeX;i++)
	{
		for (int j=0;j<CellSizeY;j++)
		{
			worldMatrix[i][j] = new GameObjectList();
		}
	}
}


bool WorldState::insertObject(GameObject* gameObject, point p)
{
	if (pointOutofBounds(p))
		return false;

	GameObjectList* currentList = getListFromPoint(p);
	currentList->push_front(gameObject);
	gameObject->location = p;
	allObjectList->push_front(gameObject);
	gameObject->worldState = this;
	return true;
}

bool WorldState::deleteObject(GameObject* gameObject)
{
	GameObjectList* currentList = getListFromPoint(gameObject->location);
	allObjectList->remove(gameObject);
	currentList->remove(gameObject);
	delete gameObject;
	return true;
}

bool WorldState::moveObject(GameObject* gameObject, point p)
{
	//replace with pixel perfect collision code
	if (pointOutofBounds(p))
	{
		gameObject->registerWallCollision();
		return false;
	}

	GameObjectList* currentList = getListFromPoint(gameObject->location);
		GameObjectList* newList = getListFromPoint(p);
		gameObject->location=p;
		if (currentList==newList)
			return true;
		newList->push_front(gameObject);
		currentList->remove(gameObject);
		return true;

}

GameObjectList* WorldState::getAtCell(point p)
{
	if (pointOutofBounds(p))
		return NULL;
	return getListFromPoint(p);
}


const GameObjectList* WorldState::getAllGameObjects(SortPreference p)
{
	switch (p)
	{
	case ACTION_SORTED:  allObjectList->sort(Action());break;
	case RENDER_SORTED:  allObjectList->sort(Render());break;
	}
	return  allObjectList; //can't change the contents of the list, but _can_ change the properties of the objects
}


bool WorldState::pointOutofBounds(point p)
{
	if (round(p.x / coarseGraining)>=CellSizeX || p.x<0 || round(p.y / coarseGraining)>=CellSizeY || p.y<0)
		return true;
	return false;

}

GameObjectList* WorldState::getListFromPoint(point p)
{
	return worldMatrix[(int)p.x / coarseGraining][(int)p.y / coarseGraining];
}