//
//  Grid.cpp
//  Rabbit_Cheetah
//
//  Created by Andrea Fiorucci on 09/02/2016.
//
//

#include "Grid.hpp"

Grid::Grid(int _row, int _col, int _x, int _y, int _blocksize,int _ofSetx,int _ofSety): row(_row),col(_col),x(_x),y(_y),blockSize(_blocksize),offSetx(_ofSetx),offSety(_ofSety)
{
    // constructor takes in rows, columns , position, blocksize, offests
    
    
}

void Grid::setup()
{
    font.loadFont("number.ttf", 40); //loading font 
    
}



void Grid::display()
{
    for (int j = 0; j < row; j++) {//loop through each row
        for (int i = 0; i < col; i++) {//loop through each column
             int x = i*blockSize+offSetx;
             int y = j*blockSize +offSety;
            //strock
            ofSetColor(255);
            ofNoFill();
            font.drawString(to_string(i+1), (i*blockSize+offSetx) + 35, 145);
            font.drawString(to_string(j+1), 15, (j*blockSize+offSety)+50);
            //draw the board
             ofRect(x, y, blockSize, blockSize);
            //setting colour for ellipses
        }
    }
}