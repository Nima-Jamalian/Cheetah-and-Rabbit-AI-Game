//
//  Entity.hpp
//  Rabbit_Cheetah
//
//  Created by Andrea Fiorucci on 15/02/2016.
//
//

#ifndef Entity_hpp
#define Entity_hpp

#include"ofMain.h"

// class entity used as a base class for rabbit and cheetah
class Entity
{
    float x; //position x
    float y; // position y
    
    
    
public:
    Entity(float _x, float _y); // constructor takes in position
    float getX(); // return x
    float getY(); // return y
    void setX(float sx); // set x
    void setY(float sy); // set y
    
    
    
};

#endif /* Entity_hpp */
