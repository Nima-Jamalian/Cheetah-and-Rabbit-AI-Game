//
//  button.cpp
//  Rabbit_Cheetah
//
//  Created by Andrea Fiorucci on 02/02/2016.
//
//

#include "button.hpp"

Button::Button(float _x, float _y, float _w, float _h):x(_x),y(_y),w(_w),h(_h)
{}
// constructor takes in position , width, height



void Button::display() // display button
{
    ofSetColor(255);
    ofNoFill();
    ofRect(x,y,w,h);
    
}



bool Button::check() // collision when hover the button 
{
    
   if(ofGetMouseX()>x&&ofGetMouseX()<x+w&&ofGetMouseY()>y&&ofGetMouseY()<y+h)
   {
       
       return true;
   }
    
    return false;
    
}