#include <cmath>
#include "Thing.h"
#include "../Subclasses/Color32.h"
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

Thing::Thing(SDL_Surface *scrn_ref, std::list<Thing>* it, int x, int y)
{
    srand(time(NULL));
    this->color_id.setRGBA(255,255,0,255);
    this->posX = x;
    this->posY = y;
    this->wait = 0;
    this->age = 0;
    this->mature = false;
    this->screen_ref = scrn_ref;
    this->vector_ptr = it;
};

bool Thing::breathe()
{
    if(age<255)
    {
        this->movement();
        this->reproduce();
        return true;
    }
    else
    {
        this->kill();
        return false;
    }
};

void Thing::kill()
{
    this->age = 255;
    this->putPixel(this->posX, this->posY,0,rand()%255,0,255);
};

SDL_Surface* Thing::getScreenRef()
{
    return this->screen_ref;
};

int Thing::getX()
{
    return this->posX;
};

int Thing::getY()
{
    return this->posY;
};

void Thing::reproduce()// TODO (argonnia#1#): Reproduction phase from update
{
    if(this->mature)
    {
        int litter = (int)rand()%8+1;
        for(int i=1;i<litter;i++)
        {
            this->vector_ptr->push_back(Thing(this->screen_ref,this->vector_ptr,this->posX,this->posY));
        }
        //this->mature=false;
        this->kill();
    }
};

void Thing::movement()
{
    if(this->wait==0)
    {
        Color32 look(this->getPixel(this->posX,this->posY+1));
        if((look.getRed()>0)&&(look.getGreen()>0)&&(look.getBlue()>0))
        {
            ;
        }
        this->putPixel(this->posX, this->posY, 0,0,0,0);
        switch(rand()%3-1)
        {
        case 1:
            this->posX+=(int)rand()%3-1;
            break;
        case 0:
            this->wait+=(unsigned char)rand()%6+1;
            break;
        case -1:
            this->posY+=(int)rand()%3-1;
            break;
        }

        if(this->posY>this->screen_ref->h-10)
        {
            this->posY = 10;
        }
        if(this->posY<10)
        {
            this->posY = this->screen_ref->h-10;
        }
        if(this->posX>this->screen_ref->w-10)
        {
            this->posX = 10;
        }
        if(this->posX<10)
        {
            this->posX = this->screen_ref->w-10;
        }

        look.setRGBA(this->getPixel(this->posX,this->posY));
        if((look.getRed()==0)&&(look.getGreen()>127)&&(look.getBlue()==0))//if I see food
        {
            this->mature = true;
        }
        else
        {
            this->age+=1;
        }
        this->putPixel(this->posX, this->posY, 255,255-age,0,255);
    }
    else
    {
        this->wait-=1;
    }
};

void Thing::putPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    unsigned int* pixels = (unsigned int*)this->screen_ref->pixels;
    unsigned int* pixel = pixels + y*(this->screen_ref->pitch/4) + x; // offset of pointer
    *pixel = SDL_MapRGBA(this->screen_ref->format,r,g,b,a);
};

Color32 Thing::getPixel(int x, int y)
{
    unsigned char r,g,b,a;
    unsigned int* pixels = (unsigned int*)this->screen_ref->pixels;
    unsigned int* pixel = pixels + y*(this->screen_ref->pitch/4) + x; // offset of pointer
    SDL_GetRGBA(*pixel, this->screen_ref->format, &r, &g, &b, &a);
    return Color32(r,g,b,a);
};
