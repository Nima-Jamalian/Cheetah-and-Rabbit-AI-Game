//
//  Cheetah.cpp
//  Rabbit_Cheetah
//
//  Created by Andrea Fiorucci on 16/02/2016.
//
//

#include "Cheetah.hpp"

Cheetah::Cheetah(float x, float y,Menu& _m,Rabbit& _rabbit,Menu& _menu,Collectable& _ct): Rabbit( x, y,_m),rabbit(_rabbit),menu(_menu),ct(_ct),storeMoves(2)
// constrctor takes in position, reference to menu,reference to rabbit,reference to collectable
{
    count_moves = 0; // not moving at the beginning
    over = false; // not game over at the beginning
   
  
}


void Cheetah::loadImage() // loading the cheetaj image
{
    c.load("ch.png");
    
}

void Cheetah:: display() // display the cheetah
{
    
    c.draw(getX(),getY(),80,80);
    
    
}



void Cheetah::always_move() // functionality added on top of the queue to simulate the cheetah always moves
{
    
    if(ofGetFrameNum()%30==0) // moves each 30 frames
    {
        
        if(rabbit.getX()<this->getX()&&rabbit.getY()<this->getY())
        {
            this->setX(this-> getX()-80);
            this->setY( this-> getY()-80);
        }
        else if(rabbit.getX()>this->getX()&&rabbit.getY()>this->getY())
        {
            this->setX( this->getX()+80);
            this->setY(this->getY()+80);
        }
        else if(rabbit.getX()>this->getX()&&rabbit.getY()<this->getY())
        {
           
            this->setX( this->getX()+80);
            this->setY(this->getY()-80);

        }
        else if(rabbit.getX()<this->getX()&&rabbit.getY()>this->getY())
        {
            this->setX( this->getX()-80);
            this->setY(   this->getY()+80);
        }
      
        else if(rabbit.getX()>this->getX()&&rabbit.getY()==this->getY())
        {
            this->setX( this->getX()+80);
            
        }
        else if(rabbit.getX()<this->getX()&&rabbit.getY()==this->getY())
        {
           
            this->setX( this->getX()-80);
            
        }
        else if(rabbit.getX()==this->getX()&&rabbit.getY()>this->getY())
        {
            
            this->setY( this->getY()+80);
        }
        else if(rabbit.getX()==this->getX()&&rabbit.getY()<this->getY())
        {
            this->setY( this->getY()-80);
        }
        
    }
        
        
        
}
    
    
    string Cheetah::moveTowards() // look for the rabbit and move toward it
{
    if(rabbit.stop==false) // if the rabbit moves
    {
    string temp;
    
    if(ofGetFrameNum()%10==0 && menu.gameState=="play") // simulation
    {
        temp = rabbit.moves.deQueue(); // dequeue the rabbit queue to know where it is
        count_moves++; // add moves to the variable
       
    }
        else if ( menu.gameState=="play1") // game one
            {
                temp = rabbit.moves.deQueue();
                count_moves++;
                // cout<<stop<<endl;
            }
    
 // maths added to the queue system to improve the cheetah ai.
        
        
    if(temp == "up" && rabbit.getY()<this->getY()&&this->getY()-rabbit.getY()>80)
    {
        temp = "up";
    }
    else if(temp == "up" && rabbit.getY()>this->getY()&&rabbit.getY()-this->getY()>80)
    {
        temp = "down";
    }
    
    
    else if(temp == "down" && rabbit.getY()<this->getY()&&this->getY()-rabbit.getY()>80)
    {
        temp = "up";
    }
    else if(temp == "down" && rabbit.getY()>this->getY()&&rabbit.getY()-this->getY()>80)
    {
        temp = "down";
    }
   
    
    else if(temp == "right" && rabbit.getX()>this->getX()&&rabbit.getX()-this->getX()>80)
    {
        temp = "right";
    }
    else if(temp == "right" && rabbit.getX()<this->getX()&&this->getX()-rabbit.getX()>80)
    {
        temp = "left";
    }
    
    
    else if(temp == "left" && rabbit.getX()>this->getX()&&rabbit.getX()-this->getX()>80)
    {
        temp = "right";
    }
    else if(temp == "left" && rabbit.getX()<this->getX()&&this->getX()-rabbit.getX()>80)
    {
        temp = "left";
    }
    //----------
    else if (rabbit.getY()<this->getY()&&this->getY()-rabbit.getY()<80){
        temp = "up";
    }
    else if (rabbit.getY()>this->getY()&&rabbit.getY()-this->getY()<80){
        temp = "down";
    }
    else if (rabbit.getX()>this->getX()&&rabbit.getX()-this->getX()<80){
        temp = "right";
    }
    else if (rabbit.getX()<this->getX()&&this->getX()-rabbit.getX()<80){
        temp = "left";
    }
    //----------
    
    else if(temp == "up" && rabbit.getY()<this->getY()&&this->getY()-rabbit.getY()==80)
    {
        temp = "up";
    }
    else if(temp == "up" && rabbit.getY()>this->getY()&&rabbit.getY()-this->getY()==80)
    {
        if (rabbit.getX()<this->getX()){
                temp = "left";
        }
        else {
                temp ="right";
        }
    }
    else if(temp == "down" && rabbit.getY()<this->getY()&&this->getY()-rabbit.getY()==80)
    {
        if (rabbit.getX()<this->getX()){
            temp = "left";
        }
        else {
            temp ="right";
        }
    }
    else if(temp == "down" && rabbit.getY()>this->getY()&&rabbit.getY()-this->getY()==80)
    {
        temp = "down";
    }
    else if(temp == "right" && rabbit.getX()>this->getX()&&rabbit.getX()-this->getX()==80)
    {
        temp = "right";
    }
    else if(temp == "right" && rabbit.getX()<this->getX()&&this->getX()-rabbit.getX()==80)
    {
        temp = " ";
    }
    else if(temp == "left" && rabbit.getX()>this->getX()&&rabbit.getX()-this->getX()==80)
    {
        temp = " ";
    }
    else if(temp == "left" && rabbit.getX()<this->getX()&&this->getX()-rabbit.getX()==80)
    {
        temp = "left";
    }
    

    
    return temp; // return the move
    }
  
    
    
}


void Cheetah::gameOver() // check for game over when the rabbit collides with the cheetah
{
   if(this->getX()==rabbit.getX() && this->getY()==rabbit.getY())
   {
       rabbit.stop = true;
       over = true;
       if(ct.score>ct.highscore)
       {
           ct.highscore = ct.score;
       }
       
       
      
   }
    
    
}
