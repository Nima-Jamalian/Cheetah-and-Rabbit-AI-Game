#pragma once

#include "ofMain.h"
#include "menu.hpp"
#include "button.hpp"
#include"grid.hpp"
#include"Priority_Queue.hpp"
#include "Rabbit.hpp"
#include"Cheetah.hpp"
#include <string>
#include <iostream>
#include"collectables.hpp"
#include"Obstacle.hpp"
using std::cout;
using std::endl;



class ofApp : public ofBaseApp {
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    Menu menu; // object of type Menu
    Grid grid; // object grid
    ofApp(); // constructor of the class ofApp
    vector <Button> buttons; // vectors of objects buttons
    float max_Buttons; // maximum number of buttons objects
    void selection(); // selection function used to select the game stage
    Rabbit rabbit;// object rabbit
    Cheetah cheetah; // object cheetah
    vector <string> empty; // vector for moves
    string moveRabbit; // string move rabbit
    string moveCheetah; // string move cheetah
    Button simulation; // button
    Button restart; // button
    Button restart1; // button
    Button random; // button
    bool rest; // restart
    bool sim; // start simulation
    Collectable collectable; // object collectables
    bool collected; // collected the collectables
    Button move; // button move
    Button pop; // button pop
    bool up; // up
    bool down; // down
    bool left; //left
    bool right;// right
    bool start;// start
    Obstacle one; // object obstacle
    Obstacle two;// object obstacle
    Obstacle three;// object obstacle
    Obstacle four;// object obstacle
    Obstacle five;// object obstacle 
   
   
   
    
    
    
    
};
