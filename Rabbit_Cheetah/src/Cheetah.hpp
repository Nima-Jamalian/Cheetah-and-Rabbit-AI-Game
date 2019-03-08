//
//  Cheetah.hpp
//  Rabbit_Cheetah
//
//  Created by Andrea Fiorucci on 16/02/2016.
//
//

#ifndef Cheetah_hpp
#define Cheetah_hpp
#include"ofMain.h"
#include"Rabbit.hpp"
#include"Menu.hpp"
#include "collectables.hpp"

// class cheetah which inherits from rabbit
class Cheetah: public Rabbit
{
    ofImage c; // image
    Rabbit& rabbit; // refernece to the object rabbit
    Menu& menu; // reference to menu object
    Collectable& ct; // reference to collectable object

   
public:
    Cheetah(float x, float y,Menu& _m, Rabbit& _rabbit,Menu& _menu,Collectable& _ct); // constructor
    void loadImage(); // load the images
    void display(); // display the cheetah
    void gameOver(); // collision and game over
    string moveTowards(); // function used for the movement
    int count_moves; // count the moves done
    void always_move(); // cheetahh always move
    bool over; // check if gameover
  
    Queue<string> storeMoves; // Queue to store the cheetah moves
  
  
    
    
    
    
    
    
    
    
    
    
    
};
#endif /* Cheetah_hpp */
