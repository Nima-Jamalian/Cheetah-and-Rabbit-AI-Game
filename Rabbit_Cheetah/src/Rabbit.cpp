//
//  Rabbit.cpp
//  Rabbit_Cheetah
//
//  Created by Andrea Fiorucci on 15/02/2016.
//
//

#include "Rabbit.hpp"
#include "ofMain.h"


Rabbit::Rabbit(float x1, float y1,Menu& _men):Entity(x1,y1),moves(2),key_moves(50),men(_men),wrong_way(50)
// constructor takes in the position and a reference to the menu
{
    
    // initialise everything to false (movements and popping the stack)
    up = false;
    left = false;
    right = false;
    down = false;
    up1 = false;
    left1 = false;
    right1 = false;
    down1= false;
    move = "stay";
    stop = false;
    popping = false;
    mov = false;
  
}


void Rabbit::loadImage() // loading the image
{
    img.load("rab.png");
}

void Rabbit::fillVector() // fill vector with 4 directions 
{
    directions.push_back("up");
    directions.push_back("down");
    directions.push_back("left");
    directions.push_back("right");
 
}


string Rabbit::randomDir(vector <string> st) // determine a random direction for the rabbit
{
    if(!stop) // if not sop
    {
    st = directions;
    int temp;
    if(ofGetFrameNum()%10==0)
    {
        temp = ofRandom(0, 4);
        if(this->getY()==160&& temp == 0)
        {
            temp = ofRandom(0,4);
        }
        if(this->getY()==720&& temp == 1)
        {
            temp = ofRandom(0,4);
        }
        if(this->getX()==40&& temp == 2)
        {
            temp = ofRandom(0,4);
        }
        if(this->getX()==1080&& temp == 3)
        {
            temp = ofRandom(0,4);
        }
        
      
        
        moves.enQueue(directions[temp]); // fill the queue with the random direction obtained
        
    }
    
    
    
    return directions[temp]; // return that direction
    }
    
    
}


void Rabbit:: display() // display the rabbit
{
    img.draw(getX(),getY(),80,80);
    
}


void Rabbit::update_key() // checking when pressing the keys and that the figure stays within the grid
{
    
    if (up && getY()>160)
        {
            float up;
            up = getY()-80;
            setY(up);
           
        }
    
    else if (right && getX()<1040)
    {
        float right;
        right = getX()+80;
        setX(right);
    }

    else if (down&&getY()<720)
    {
        float down;
        down = getY()+80;
        setY(down);
    }

    else if (left&&getX()>40)
    {
        float left;
        left = getX()-80;
        setX(left);
    }
    else if (left&&up)
    {
        left = false;
         up = false;
    }
    
    
}

void Rabbit::move_c() // used in level 2 when you can move the rabbit when selecting the keys
{
    string temp;
  
    if (key_moves.isEmpty() == false)
    {
     temp = key_moves.deQueue();
    }
    
    if (temp == "up"&&getY()>160)
    {
        float up;
        up = getY()-80;
        setY(up);
        
    }
    
    else if (temp == "right" && getX()<1040)
    {
        float right;
        right = getX()+80;
        setX(right);
    }
    
    else if (temp=="down"&&getY()<720)
    {
        float down;
        down = getY()+80;
        setY(down);
    }
    
    else if (temp == "left"&&getX()>40)
    {
        float left;
        left = getX()-80;
        setX(left);
    }

    
    
    
    
    
}

void Rabbit::back_c()  // if you make a mistake you can pop your last route bacj to the beginning
{
    if (wrong_way.get_top()==-1)
    {
        popping = false;
        move = false;
      
        
        
    }
    string temp;
    if(popping)
    {
    temp = wrong_way.pop(); // pop back the stack and reverce movements
  
    
    if (temp == "down"&&getY()>160)
    {
        float up;
        up = getY()-80;
        setY(up);
        
    }
    
    else if (temp == "left" && getX()<1040)
    {
        float right;
        right = getX()+80;
        setX(right);
    }
    
    else if (temp=="up"&&getY()<720)
    {
        float down;
        down = getY()+80;
        setY(down);
    }
    
    else if (temp == "right"&&getX()>40)
    {
        float left;
        left = getX()-80;
        setX(left);
    }
    
    
    
    }
    
    
}


void Rabbit::update_auto(string m) // checking for movements
{

    
    if (m == "up"&&getY()>160)
    {
        float up;
        up = getY()-80;
        setY(up);
        
    }
    
    else if (m == "right" && getX()<1040)
    {
        float right;
        right = getX()+80;
        setX(right);
    }
    
    else if (m=="down"&&getY()<720)
    {
        float down;
        down = getY()+80;
        setY(down);
    }
    
    else if (m == "left"&&getX()>40)
    {
        float left;
        left = getX()-80;
        setX(left);
    }
    
}
    


void Rabbit::keyDown(int i) // using keyPressed inside the class
{
    
    switch(i)
    {
       
        case 97: //move left if a is pressed
            left = true;
            right = false;
            down = false;
            up1 = false;
            left1 = false;
            right1 = false;
            down1= false;
            up = false;
            if(men.gameState == "play2") // if the game is 2 enqueue and push the stack too
            {
              
                cout<<key_moves.enQueue(directions[2])<<endl;
                wrong_way.push(directions[2]);
            }
            
            
//update_key();
            
            break;
        case 119: // move up if w is pressed
            left = false;
            right = false;
            down = false;
            up1 = false;
            left1 = false;
            right1 = false;
            down1= false;
            up = true;
            if(men.gameState == "play2")// if the game is 2 enqueue and push the stack too
            

            {
            
            cout<<key_moves.enQueue(directions[0])<<endl;
            wrong_way.push(directions[0]);
            }
           
 //update_key();
            break;
        case 100://"d" move right
            left = false;
            right = true;
            down = false;
            up1 = false;
            left1 = false;
            right1 = false;
            down1= false;
            up = false;
            if(men.gameState == "play2")
            {
               
                cout<<key_moves.enQueue(directions[3])<<endl;
                wrong_way.push(directions[3]);
            }
          
 //update_key();
            break;
        case 115://"s" move down
            left = false;
            right = false;
            down = true;
            up1 = false;
            left1 = false;
            right1 = false;
            down1= false;
            up = false;
            if(men.gameState == "play2")
            {
               
                cout<<key_moves.enQueue(directions[1])<<endl;
                wrong_way.push(directions[1]);
            }
           
 //update_key();
            break;
        case 109 :
          
            
            break;
    }
}

    void Rabbit::keyUp(int i) // using keyReleased and apply the inverse of above, setting all variables to false 
    {
        
        switch(i)
        {
                
            case 97: //"a"
                left = false;
                right = false;
                down = false;
                up1 = false;
                left1 = false;
                right1 = false;
                down1= false;
                up = false;
               
                
                break;
            case 119: //"w"
                left = false;
                right = false;
                down = false;
                up1 = false;
                left1 = false;
                right1 = false;
                down1= false;
                up = false;
                
                break;
            case 100://"d"
                left = false;
                right = false;
                down = false;
                up1 = false;
                left1 = false;
                right1 = false;
                down1= false;
                up = false;
                
                break;
            case 115://"s"
                left = false;
                right = false;
                down = false;
                up1 = false;
                left1 = false;
                right1 = false;
                down1= false;
                up = false;
                break;
            case 109 :
                
                
                break;
        }

}




    

