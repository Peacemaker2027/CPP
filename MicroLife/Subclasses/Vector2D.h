#ifndef VECTOR2D
#define VECTOR2D

class Vector2D
{
public:
    Vector2D(float data1=0.0, float data2=1.0, bool polar=true);
    Vector2D(const Vector2D &vec);
    void setVector2D(float data1=0.0, float data2=1.0, bool polar=true);
    Vector2D& operator=(const Vector2D &vec);
    float getAngle() const;
    float getRadius() const;
    float getX() const;
    float getY() const;
private:
    float x,y,angle,radius;
};
#endif
