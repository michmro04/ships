#include "ship.h"
using namespace std;

bool Ship::isSunk(){
    return hits==length;
}

void Ship::setLength(int length){
    length = length;
}

int Ship::getLength(){
    return length;
}
