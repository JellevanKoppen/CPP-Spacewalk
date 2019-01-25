#ifndef SPACESHIP_H
#define SPACESHIP_H

class Spaceship{
  public:
    void setSize(int _size);
    void setID(int _id);
    void setLocation(int location);
    int getLocation();
    int getID();
    int getSize();
    ~Spaceship();
    Spaceship(int _size, int _id);
    Spaceship();
    void sayHi();
  private:
    int size;
    int location;
    char const* sizeText;
    int id;
};
#endif
