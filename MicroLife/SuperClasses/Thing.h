#include <SDL2/SDL.h>
#include <list>
#include "../Subclasses/Color32.h"
#ifndef THING
#define THING

class Thing
{
public:
    Thing(SDL_Surface*, std::list<Thing>*, int, int);
    bool breathe();
protected:
    SDL_Surface* getScreenRef();
    int getX();
    int getY();
    void kill();
private:
    void reproduce();
    void movement();
    void putPixel(int, int, unsigned char, unsigned char, unsigned char, unsigned char);
    Color32 getPixel(int, int);

    int posX,posY;
    unsigned char wait,age;
    bool mature;
    Color32 color_id;
    SDL_Surface* screen_ref;
    std::list<Thing> *vector_ptr;
};

#endif // THING
