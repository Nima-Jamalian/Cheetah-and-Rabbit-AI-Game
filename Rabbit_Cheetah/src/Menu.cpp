//
//  Menu.cpp
//  Rabbit_Cheetah
//
//  Created by Andrea Fiorucci on 02/02/2016.
//
//

#include "Menu.hpp"

#include "Menu.hpp"
// takes in position x and y, three strings for displaying text
Menu::Menu(float _x, float _y,string _a,string _b,string _c):x(_x),y(_y),a(_a),b(_b),c(_c)
{
x1 = _x; // staring position of the arrows
x2 = _x; // starting position of the arrows
right = true; // arrow start moving right
   
}

//------Load images and text font
void Menu::setup()
{
    // loading images inside a vector
    for (int i = 0; i<7;i++)
    {
        ofImage temp;
        string text = to_string(i);
        temp.loadImage(text+".png");
        images.push_back(temp);
    }
    
    font.load("font.tff",40); // loading fonts
    font1.load("font.tff",20);// loading fonts 
    gameState = "menu"; // game start from the main menu stage
    
    
    
}



//---------- Main Menu-------------------
void Menu::displayStart()
{
    // menu design
    ofBackground(0);
    images[3].draw(170,600,100,200);
    images[4].draw(900,600,100,200);
    images[2].draw(170,30);
    images[1].draw((x1-55),y-91,70,40);
    images[0].draw(x2+178,y-91,70,40);
    font.drawString(a, x+30, y-50);
    font.drawString(b, x-57, y+100);
    
    
    
    
    
}

//---------- Play Section-------------------

void Menu::play()
{
    ofBackground(0);
    
}

// animating the arrow to make the menu more realistic ( arrow movement left and right)
void Menu::updateArrowPlay()
{
    
    if (x1>500)
    {
        right = false;
    }
    else if (x1<480)
    {
        right = true;
    }
    
    if (right)
    {
        x1++;
        x2--;
    }
    else
    {
        x1--;
        x2++;
    }
    
    
    
    
    
    
    
    
}
//---------- Main Menu with arrows pointing to the section "how to play"
void Menu::displayHow()
{
    ofBackground(0);
    images[3].draw(170,600,100,200);
    images[4].draw(900,600,100,200);
    images[2].draw(170,30);
    images[1].draw(x1-145,y+60,70,40);
    images[0].draw(x2+270,y+60,70,40);
    font.drawString(a, x+30, y-50);
    font.drawString(b, x-57, y+100);
    
}
//---------- How to play section-----------------------
void Menu::displayBack()
{
    ofBackground(0);
    images[2].draw(170,30);
    images[1].draw(x1-50,y+410,70,40);
    images[0].draw(x2+177,y+410,70,40);

    font.drawString(c, x+35, y+450);
}

//---------- display the menu winning  stage-----------------
void Menu::displayCredits()
{
    
    ofBackground(0);
    images[5].draw(170,170);
    
}

//---------- display the menu instructions  stage---------------
void Menu :: instructions()
{
 
    images[6].draw(100,30,1000,750);
    
}

//-------------------------- menu logic to change among different stages
void Menu::condition(int key)
{
    if(key == OF_KEY_UP && gameState == "menu")
    {
        sel = true; // aniamtion boolean for the menu
    }
    else if(key == OF_KEY_DOWN && gameState == "menu")
    {
        sel = false; // aniamtion boolean for the menu
    }
    
    else if (key == OF_KEY_RETURN && select() ==true && gameState == "menu")
    {
        
        gameState ="play"; // change the state if press enter
        
        
    }
    else if (key == OF_KEY_RETURN && select() ==false && gameState == "menu")
    {
        gameState ="how"; // change the state if press enter
    }
    else if (key == OF_KEY_BACKSPACE && (gameState=="play"||gameState=="play1"||gameState=="play2"||gameState=="play3"))
    {
        gameState ="menu"; // change the state if press esc
    }
    else if (key == OF_KEY_RETURN && gameState == "how")
    {
        gameState ="menu"; // change the state if press esc
    }
    else if (key == OF_KEY_RETURN && gameState == "win")
    {
        gameState ="menu"; // change the state if press esc
    }
    else if (key == OF_KEY_RETURN && gameState == "lose")
    {
        gameState ="menu"; // change the state if press esc
    }
    
    
}

//-------------------- returning true is bool sel = true, used to animate the menu
bool Menu::select()
{
    if (sel == true)
    {
        return true;
    }
    else if(sel == false)
    {
        return false;
    }
}