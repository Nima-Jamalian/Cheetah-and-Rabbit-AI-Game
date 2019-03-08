//
//  Rabbit.hpp
//  Rabbit_Cheetah
//
//  Created by Andrea Fiorucci on 15/02/2016.
//
//

#ifndef Rabbit_hpp
#define Rabbit_hpp

#include <ofMain.h>
#include <string>
#include <iostream>
#include "Entity.hpp"
#include "Priority_Queue.hpp"
#include"Stack.hpp"
#include"Menu.hpp"


// class Rabbit inheriting from entity
using std::cout;
using std::endl;

class Rabbit: public Entity
{
    ofImage img; // display the rabbit image
    bool up; // move up
    bool down; // move down
    bool left; // move left
    bool right; // move right
    bool up1; // used for another level
    bool down1;// used for another level
    bool left1;// used for another level
    bool right1;// used for another level
    string move; // store the move in a string
    Menu& men; // reference to the menu
  

   
    
  
   
    
public:
    Queue<string> moves; // store the rabbit moves in a queue
    Queue<string> key_moves; // store the rabbit moves in a queue when rabbit is controlled with the keyboard
    Stack<string> wrong_way; // stack when storing the rabbit values used in the last level (game_2)
    vector <string> directions; // vector strig which contains the directions
    Rabbit(float x1,float y1,Menu& _men); // constructor takes in position and a reference to the menu
    void update_key(); // updating the key
    void update_auto(string m); //
    void move_c();
    void back_c();
    void keyDown(int key); // key pressed
    void keyUp(int key); // key released
    void loadImage(); // loading images
    void display(); // display the rabbit
    bool popping; // can we pop?
    void fillVector(); // used to fill the vector string with 4 directions 
    string randomDir(vector <string> st);
    bool stop;
    bool mov;
    
    
};

#endif /* Rabbit_hpp */


