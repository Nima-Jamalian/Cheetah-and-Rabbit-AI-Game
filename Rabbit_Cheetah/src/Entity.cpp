//
//  Entity.cpp
//  Rabbit_Cheetah
//
//  Created by Andrea Fiorucci on 15/02/2016.
//
//

#include "Entity.hpp"
Entity::Entity(float _x, float _y):x(_x),y(_y) // constructor takes in the position of the base class
{}



float Entity:: getX()
{
    return x; // return x
}

float Entity:: getY()
{
    return y; // return y
}


void Entity:: setX(float sx)
{
    x = sx; //set x
}

void Entity:: setY(float sy)
{
    y = sy; // set y
}