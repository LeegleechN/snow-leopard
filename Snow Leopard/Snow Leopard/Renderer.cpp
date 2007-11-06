#include "GameObject.h"
#include "WorldState.h"
#include <SDL.h>
#include <SDL_TTF.h>
#include "Renderer.h"
#include <iostream>
#include "SDL_image.h"


SDL_Surface* Renderer::load_image( std::string filename ) 
{
    SDL_Surface* loadedImage;
    SDL_Surface* optimizedImage;

	loadedImage =  IMG_Load( filename.c_str());
    optimizedImage = SDL_DisplayFormat( loadedImage );
        
    SDL_FreeSurface( loadedImage );

    return optimizedImage;
}

bool Renderer::LoadImages(GameObjectQueue* queue)
{
	for (int i = 0;i<queue->size();i++)
	{
		GameObject* obj = queue->top();
		queue->pop();
		SDL_Surface* ptr = load_image(obj->imageSource);

		//might want to make sourceSize have height and width,
		//to support rectangles instead of just squares
		obj->sourceSize = ptr->w; 
		obj->displaySize = ptr->w;
		
		imageMap[obj->ID] = ptr;
	}
	return true;
}
bool Renderer::Render(WorldState* state)
{
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0)); //clear the screen
	for (int x = 0;x<state->xsize;x++)
	{
		for (int y = 0;y<state->ysize;y++)
		{
			GameObjectList* list = state->getAtLocation(new point(x,y));
			if (list==NULL)
				continue;
			GameObjectIter itr;
			for (itr = list->begin();itr!=list->end();itr++)
			{
				GameObject* obj = *itr;
				SDL_Rect* dest_rect;
				dest_rect = new SDL_Rect();
				dest_rect->x = obj->location.x - obj->displaySize / 2;
				dest_rect->y = obj->location.y - obj->displaySize / 2;
				SDL_BlitSurface( imageMap[obj->ID], NULL, screen, dest_rect );
			}
		}
	}

	SDL_Flip(screen);
	return true;
}

bool Renderer::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
    atexit(TTF_Quit);
	atexit(SDL_Quit);

	SDL_WM_SetCaption( "Snow Leopard", NULL );

    screen = SDL_SetVideoMode( 0, 0, 0, SDL_RESIZABLE | SDL_HWSURFACE | SDL_DOUBLEBUF);
	int screenWidth = SDL_GetVideoInfo()->current_w;
	int screenHeight = SDL_GetVideoInfo()->current_h;
	return true;
}
