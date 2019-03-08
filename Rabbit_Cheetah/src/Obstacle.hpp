//
//  Obstacle.hpp
//  Rabbit_Cheetah
//
//  Created by Andrea Fiorucci on 25/02/2016.
//
//

#ifndef Obstacle_hpp
#define Obstacle_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Cheetah.hpp"

// class obstacles used in the game_two tab
class Obstacle
{
    Cheetah& ch; // reference to cheetah
public:
    float x; // x position
    float y; // y position
    ofImage obj; // image
    Obstacle(float _x, float _y,Cheetah & _ch); // constructor
    bool collision(); // return true or false if a collision is detected
    void load(); // load image
    void display(); // display the obstacle
};

#endif /* Obstacle_hpp */
