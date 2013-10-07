#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>
#include "Subclasses/Color32.h"
#include "Superclasses/Thing.h"
#include <list>
#include <stdio.h>

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
void close();

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;

int main( int argc, char* args[] )
{
    list<Thing> things;
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
	    for(int i=0;i<1000;i++)
        {
            things.push_back(Thing(gScreenSurface,&things,320,240));
        }
        bool quit = false;
        SDL_Event e;
        while( !quit )
        {
            while( SDL_PollEvent( &e ) != 0 )
            {
                if( e.type == SDL_QUIT )
                {
                    quit = true;
                }
            }
            if(!things.empty())
            {
                for(list<Thing>::iterator itr = things.begin(); itr!=things.end(); ++itr)
                {
                    if(!itr->breathe())
                    {
                        things.erase(itr++);
                    }
                }
            }
            else
            {
                //quit = true;
            }
            SDL_UpdateWindowSurface( gWindow );
        }
	}
	close();
	return 0;
}

void close()
{
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	SDL_Quit();
}

bool init()
{
	bool success = true;
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}
	return success;
}

/*int main(int argc, char** argv)
{
    vector<Thing> things;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Surface *screen;
    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
    bool running = true;
    const int FPS = 30;
    Uint32 start;

    for(int i=0;i<4;i++)
    {
        things.push_back(Thing(screen,&things,320,240));
    }

    while(running)
    {
        start = SDL_GetTicks();
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
                    running = false;
                    break;
            }
        }
        SDL_Flip(screen);
        if(1000/FPS > SDL_GetTicks()-start)
        {
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
        }
        for(vector<Thing>::iterator itr = things.begin(); itr!=things.end(); itr++)
        {
            itr->update();
        }
    }
    SDL_Quit();
    return 0;
}*/
