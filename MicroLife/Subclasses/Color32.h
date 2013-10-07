#ifndef COLOR32
#define COLOR32

class Color32
{
public:
    Color32();
    Color32(unsigned int);
    Color32(unsigned char, unsigned char, unsigned char, unsigned char);
    void setRGBA(unsigned char, unsigned char, unsigned char, unsigned char);
    void setRGBA(Color32);
    unsigned char getRed() const;
    unsigned char getGreen() const;
    unsigned char getBlue() const;
    float getAlpha() const;
    unsigned int getRGBA() const;
private:
    unsigned int rgba;
};

#endif // SDL_COLOR
