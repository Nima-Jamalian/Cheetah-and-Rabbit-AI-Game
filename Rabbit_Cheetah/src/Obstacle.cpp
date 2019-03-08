//
//  Obstacle.cpp
//  Rabbit_Cheetah
//
//  Created by Andrea Fiorucci on 25/02/2016.
//
//

#include "Obstacle.hpp"


Obstacle::Obstacle (float _x, float _y,Cheetah& _ch):ch(_ch) // takes in position and reference to player cheetah
{
    x = _x;
    y = _y;
}


void Obstacle::load() // load the image
{
    obj.load("obj.png");
    
}


void Obstacle::display() // display the image
{
    
    obj.draw(x,y);
    
}

bool Obstacle::collision() // collision with object, cheetah and obstacle 
{
    if (ch.getX()==x&&ch.getY()==y)
    {
        return true;
        
    }
    
    return false;
    
}