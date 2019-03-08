//
//  Menu.hpp
//  Rabbit_Cheetah
//
//  Created by Andrea Fiorucci on 02/02/2016.
//
//

#ifndef Menu_hpp
#define Menu_hpp
#include"ofMain.h"


class Menu
{
public:
    
    float x; // x value
    float y; // y value
    float x1; // used to update the arrow animation in the main menu
    float x2; // used to update the arrow animation in the main menu
    string a,b,c; // menu options text string
    ofTrueTypeFont font; // font main menu
    ofTrueTypeFont font1; // other font
    vector <ofImage> images; // arrow animation images
    bool right; // used with the arrow animation
    
    
    
    
    //------------- Menu Design--------------------------------------
    
    bool sel = true; // checking which menu option is selected
    string gameState; // used to check the game state section
    
    
public:
    Menu(float _x, float _y,string _a,string _b,string _c); // constructor position,three string text
    void setup();//Load images and text font
    void displayStart(); // arrows on start
    void play();
    void displayHow(); // arrows on how to play
    void displayBack(); // back button on how to play section
    void displayCredits(); // win menu design
    void condition(int key); // different stages based on key pressed
    bool select(); // selected stage of the game
    void instructions(); // game instructions
    void updateArrowPlay(); // update arrow animation in the menu
    
    
    
    
    
    
    
    
    
};

#endif /* Menu_hpp */
