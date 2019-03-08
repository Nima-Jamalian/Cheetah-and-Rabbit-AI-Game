//
//  collectables.cpp
//  Rabbit_Cheetah
//
//  Created by Andrea Fiorucci on 18/02/2016.
//
//

#include "collectables.hpp"


Collectable::Collectable(float _x, float _y, float _radius,Rabbit& _r):x(_x),y(_y),radius(_radius),r(_r)
{
    score = 0; // set score to 0
    highscore = 0; // set highscore to 0
}



bool Collectable::collision() // checking for collision between the collectables and the rabbit
{
    if (this->x == (r.getX()+40) &&this->y == (r.getY()+40) )
        {
            return true;
            
           
        }
        return false;
}



void Collectable:: update() // randomise each time it is collected
{
    
    x = 80+(80*int(ofRandom(13)));
    y = 200+(80*int(ofRandom(8)));
    
    
}

void Collectable::display() // display collectables in the grid
{
    ofPushStyle();
    ofSetColor(200, 200, 0);
    ofFill();
    ofCircle(x, y, radius);
    ofPopStyle();
}