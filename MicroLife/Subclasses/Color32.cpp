#include "Color32.h"
#include <iostream>

using namespace std;

Color32::Color32(){};

Color32::Color32(unsigned int rgba)
{
    this->rgba = rgba;
};

Color32::Color32(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
    this->rgba = this->rgba^alpha;
    this->rgba = this->rgba<<8;
    this->rgba = this->rgba^blue;
    this->rgba = this->rgba<<8;
    this->rgba = this->rgba^green;
    this->rgba = this->rgba<<8;
    this->rgba = this->rgba^red;
};

void Color32::setRGBA(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
    this->rgba = this->rgba^alpha;
    this->rgba = this->rgba<<8;
    this->rgba = this->rgba^blue;
    this->rgba = this->rgba<<8;
    this->rgba = this->rgba^green;
    this->rgba = this->rgba<<8;
    this->rgba = this->rgba^red;
};

void Color32::setRGBA(Color32 color)
{
    this->setRGBA(color.getRed(),color.getGreen(),color.getBlue(),color.getAlpha());
};

unsigned char Color32::getRed() const
{
    unsigned int result = this->rgba<<24;
    return result>>24;
};

unsigned char Color32::getGreen() const
{
    unsigned int result = this->rgba<<16;
    return result>>24;
};

unsigned char Color32::getBlue() const
{
    unsigned int result = this->rgba<<8;
    return result>>24;
};

float Color32::getAlpha() const
{
    return (float)((unsigned char)(this->rgba>>24)/255);
};

unsigned int Color32::getRGBA() const
{
    return this->rgba;
};
