//
//  button.hpp
//  Rabbit_Cheetah
//
//  Created by Andrea Fiorucci on 02/02/2016.
//
//

#ifndef button_hpp
#define button_hpp
#include "ofMain.h"
// class button used to create buttons in the play section
class Button
{
public:
    float x; // x position
    float y; // y position
    float w;//  w position
    float h;// h position
    
    
    
    
    Button (float _x, float _y, float _w, float _h); // constructor takes in position and size of each object
    
    
    void display(); // display the button
    bool check(); // check for collision 
   
    
    
    
    
    
    
    
    
    
};

#endif /* button_hpp */
