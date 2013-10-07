#include "Vector2D.h"
#include <cmath>

using namespace std;

Vector2D::Vector2D(float data1, float data2, bool polar)
{
    if(polar)
    {
        this->angle = data1;
        this->radius = abs(data2);
        this->x = this->radius*cos(this->angle*3.14159/180.0);
        this->y = this->radius*sin(this->angle*3.14159/180.0);
    }
    else
    {
        this->x = data1;
        this->y = data2;
        this->angle = atan2(this->y,this->x)*180/3.14159;
        this->radius = sqrt(pow(this->x,2.0)+pow(this->y,2.0));
    }
};

Vector2D::Vector2D(const Vector2D& vec)
{
    this->angle = vec.getAngle();
    this->radius = vec.getRadius();
    this->x = vec.getX();
    this->y = vec.getY();
};

void Vector2D::setVector2D(float data1, float data2, bool polar)
{
    if(polar)
    {
        this->angle = data1;
        this->radius = abs(data2);
        this->x = this->radius*cos(this->angle*3.14159/180.0);
        this->y = this->radius*sin(this->angle*3.14159/180.0);
    }
    else
    {
        this->x = data1;
        this->y = data2;
        this->angle = atan2(this->y,this->x)*180/3.14159;
        this->radius = sqrt(pow(this->x,2.0)+pow(this->y,2.0));
    }
};

Vector2D& Vector2D::operator=(const Vector2D &vec)
{
    this->angle = vec.getAngle();
    this->radius = vec.getRadius();
    this->x = vec.getX();
    this->y = vec.getY();
    return *this;
};

float Vector2D::getAngle() const
{
    return this->angle;
};

float Vector2D::getRadius() const
{
    return this->radius;
};

float Vector2D::getX() const
{
    return this->x;
};

float Vector2D::getY() const
{
    return this->y;
};
