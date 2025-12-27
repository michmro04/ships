#ifndef SHIP_H
#define SHIP_H

class Ship{
    private:
    int length;
    int hits;

    public:
    bool isSunk();
    void setLength(int length);
    int getLength();
};
#endif