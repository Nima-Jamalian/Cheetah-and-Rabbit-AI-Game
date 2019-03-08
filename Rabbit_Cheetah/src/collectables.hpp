//
//  collectables.hpp
//  Rabbit_Cheetah
//
//  Created by Andrea Fiorucci on 18/02/2016.
//
//

#ifndef collectables_hpp
#define collectables_hpp

#include <stdio.h>
#include "ofMain.h"
#include"Rabbit.hpp"

// class collectables used for the score system

class Collectable
{
    
    float radius; // radius for collision
    Rabbit& r; // reference to the rabbit
    
public:
    Collectable(float _x, float _y, float _radius,Rabbit& _r); // constructor takes in position,radius and a reference to the rabbit
    void display(); // display the collectable
    void update(); // randomise the collectable
    bool collision(); // check when picked up
    float x; // x
    float y; // y
    int score; // score
    int highscore; // highscore
    
    
};
#endif /* collectables_hpp */