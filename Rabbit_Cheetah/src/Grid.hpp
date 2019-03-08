//
//  Grid.hpp
//  Rabbit_Cheetah
//
//  Created by Andrea Fiorucci on 09/02/2016.
//
//

#ifndef Grid_hpp
#define Grid_hpp
#include"ofMain.h"

// class grid to draw the grid game 
class Grid
{
public:
    int row; // grid rows
    int col; // grid colums
    int x; //x position
    int y; // y position
    int blockSize; // block size
    int offSetx; // used for the grid
    int offSety; // used for the grid
    ofTrueTypeFont font; // font
    Grid(int _row, int _col, int _x, int _y, int _blocksize,int _ofSetx,int _ofSety); // construcotr
    void display(); // display the grid
    void setup(); // set up images 
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};

#endif /* Grid_hpp */







