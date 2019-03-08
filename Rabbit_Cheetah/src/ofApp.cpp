#include "ofApp.h"

// Andrea Fiorucci
// Seyednima Jamalianardakani
// term two coursework
// submission date 02/03/2016




// constructor of the class ofApp with the objects creation
ofApp::ofApp() :
menu(500, 400, "Start", "How to Play", "Back"),
grid(8,14,0,0,80,40,160),
cheetah(1080,720,menu,rabbit,menu,collectable),
rabbit(40,160,menu),
simulation(ofGetWidth()/2-560,ofGetWindowHeight()-75,300,50),
restart(ofGetWidth()/2+260,ofGetWindowHeight()-75,300,50),
random(ofGetWidth()/2-560,ofGetWindowHeight()-75,300,50),
restart1(ofGetWidth()/2+260,ofGetWindowHeight()-75,300,50),
collectable(160,440,10,rabbit),
move(ofGetWidth()/2+410,ofGetWindowHeight()-75,150,50),
pop(ofGetWidth()/2+240,ofGetWindowHeight()-75,150,50),
one(40,160,cheetah),
two(40,160,cheetah),
three(40,160,cheetah),
four(40,160,cheetah),
five(40,160,cheetah)
//list of object creations
{}


//------------------------------------------SETUP--------------------------------------------------------------
void ofApp::setup() {
    
    up = false; // not up
    down = false; // not down
    left = false; // not left
    right = false; // not right
    collected = false; // not collected
    start = true; // start true
    moveRabbit = ""; // empty string movement
    moveCheetah= ""; // empty string movement
    sim = false; // not simulation
    rest = false;// not restart
    menu.setup(); // loading menu images
    menu.gameState = "menu"; // game starts from the main menu
    max_Buttons = 4; // how many sections we want?
    // creating buttons based on how many section of the game we want to use
    for (int i = 0; i<max_Buttons; i++)
    {
        float temp = ofGetWidth() / (max_Buttons);
        buttons.push_back(Button((i*temp), 2, temp, 70));
    }
    grid.setup(); // setup the grid
    rabbit.loadImage(); // load images for rabbit
    cheetah.loadImage(); // load images for cheetah
    rabbit.fillVector(); // fill vector for rabbit
    cheetah.fillVector(); // fill vector for ceetah
    one.load(); // trap
    two.load(); // trap
    three.load(); // trap
    four.load(); // trap
    five.load(); // trap
}

//--------------------------------UPDATE--------------------------------------------------------------------
void ofApp::update()
{
    
    
    menu.updateArrowPlay(); // arrows animatino in the main menu
    
    if(ofGetFrameNum()%20==0 && menu.gameState == "play"&&sim&&rabbit.stop==false) // every twenty frames update the rabbit movements and cheetah
    {
        moveRabbit = rabbit.randomDir(empty); // random rabbit
        moveCheetah = cheetah.moveTowards(); // cheetah moves towards the rabbit
        rabbit.update_auto(moveRabbit); // update rabbit
        cheetah.update_auto(moveCheetah); // update the cheetah
        cheetah.always_move();// add maths to the data structure yo make the cheetah more efficient
    }
    if( menu.gameState == "play1") // game _1
    {
        
        cheetah.always_move(); // always move the cheetah
        if(collected) // check for collectables
        {
            collectable.update();
            collected = false;
        }
    }
    
    if ( menu.gameState == "play2"&& cheetah.mov) // moving cheetah in the game_2
    {
        
        if(ofGetFrameNum()%20==0)
            cheetah.move_c(); // move using the keys
        
        if (cheetah.key_moves.isEmpty()) // check if the queue is empty
        {
            cheetah.mov = false; // do not move any more
        }
    }
    
    if ( menu.gameState == "play2"&& cheetah.popping) // check if we can pop th stack
    {
        
        if(ofGetFrameNum()%20==0)
            cheetah.back_c(); // pop the stack to go back if possible
    }
    
    
}



//--------------------------------DRAW---------------------------------------------------------------
void ofApp::draw() {
    
    
    if (menu.gameState == "menu") // if we are in the menu
    {
        
        if (menu.select())
        {
            menu.displayStart(); // start section of the menu arrows
            
        }
        else
        {
            menu.displayHow();// how to play section of the menu arrows
        }
        
        
        
    }
    //-------------------------- HOW TO PLAY MENU STATE--------------------------------------------------------
    
    else if (menu.gameState == "how") // how to play main menu section
    {
        menu.displayBack(); // back display button in how to play section
        menu.instructions(); // display the instructions
        
    }
    //----------------------------- GAME STARTS ---------------------------------------------------------------
    
    else if (menu.gameState == "play") // start with the game section
    {
        menu.play(); // display a background
        for (auto& but : buttons) // display the top buttons
        {
            but.display();
            
        }
        rabbit.display(); // display the rabbit
        cheetah.display(); // display the cheetah
        cheetah.gameOver(); // chack for game over
        simulation.display(); // button simulation is played
        restart.display(); // restart button
        
        if (rabbit.stop==false) // if rabbit is moving
        {
            grid.font.drawString("Number of moves:  "+to_string(cheetah.count_moves), 450, 860); // print number of moves
        }
        else{
            grid.font.drawString("Cheetah got the rabbit in "+to_string(cheetah.count_moves)+" moves", 400, 860); // game over printed
        }
        
        if(!sim) // no simulation
        {
            grid.font.drawString("SIMULATE", 120, 860); // button simulate
        }
        else
            grid.font.drawString("    STOP", 120, 860); // button stop
        grid.font.drawString("RESTART/RANDOM", 880, 860); // button random
        
        
        if(rabbit.stop == true){ // if rabbit not moving insert game over red revtangle
            ofPushStyle();
            ofSetColor(255, 0, 0,100);
            ofFill();
            ofRect(40, 160, 1120, 640);
            ofPopStyle();
        }
        
    }
    
    //-----------------------------------------------------------GAME_1 STARTS-----------------------------------------
    else if (menu.gameState == "play1") // game section 1
    {
        menu.play();
        for (auto& but : buttons) // display the buttons
        {
            but.display();
            
        }
        rabbit.display();// display the rabbit
        cheetah.display();// display the cheetah
        collectable.display();// displaycollectables
        if(collectable.collision()) // checking for collectables collision and if true score++
        {
            collected = true;
            collectable.score++;
        }
        // drawing graphic
        ofPushStyle();
        ofSetColor(200, 200, 0);
        ofFill();
        grid.font.drawString(to_string(collectable.score), 660, 860);
        grid.font.drawString(to_string(collectable.highscore), 220, 860);
        ofPopStyle();
        grid.font.drawString("SCORE: ", 550, 860);
        grid.font.drawString("HIGHSCORE: ", 40, 860);
        cheetah.gameOver(); // check for game over
        if(cheetah.over == true){ // if over display the red screen and restart button
            
            ofSetColor(255, 0, 0,100);
            ofFill();
            ofRect(40, 160, 1120, 640);
            restart1.display();
            grid.font.drawString("       RESTART", 880, 860);
            
        }
        
        
    }
    else if (menu.gameState == "play2") // game sectin 2
    {
        menu.play();
        rabbit.display();
        cheetah.display();
        move.display();
        pop.display();
        random.display();
        cheetah.gameOver();
        grid.font.drawString(" RANDOMISE", 90, 860);
        if(cheetah.mov == false)
        {
            grid.font.drawString("          MOVE", 960, 860);
            grid.font.drawString("          BACK", 790, 860);
        }
        for (auto& but : buttons) // display the buttons
        {
            but.display();
            
        }
        
        // display last move based on last key pressed
        if(up)
        {
            grid.font.drawString("Last move entered: UP", 450, 860);
            
        }
        else if(down)
        {
            grid.font.drawString("Last move entered: DOWN", 450, 860);
            
        }
        else if(right)
        {
            grid.font.drawString("Last move entered: RIGHT", 450, 860);
            
        }
        else if(left)
        {
            grid.font.drawString("Last move entered: LEFT", 450, 860);
            
        }
        
        else if(start)
        {
            grid.font.drawString("INSERT A MOVE USING W,S,A,D", 380, 860);
        }
        // display obstacles (5 of them)
        one.display();
        two.display();
        three.display();
        four.display();
        five.display();
        if(cheetah.over == true){ // reset queue,stack and game over
            cheetah.wrong_way.setTop(-1);
            cheetah.key_moves.setFront(0);
            cheetah.key_moves.setBack(0);
            ofPushStyle();
            ofSetColor(0, 255, 0,100);
            ofFill();
            ofRect(40, 160, 1120, 640);
            ofPopStyle();
        }
        
        if (one.collision()||two.collision()||three.collision()||four.collision()||five.collision()) // collision with obstacles
            
        {
            ofPushStyle();
            ofSetColor(255, 0, 0,100);
            ofFill();
            ofRect(40, 160, 1120, 640);
            ofPopStyle();
            cheetah.key_moves.setBack(0);
            cheetah.key_moves.setFront(0);
        }
        
    }
    else if (menu.gameState == "play3") // credits
    {
        menu.play();
        menu.displayCredits(); // display credits
        for (auto& but : buttons) // display the buttons
        {
            but.display();
            
        }
        
        
    }
    
    if (menu.gameState == "play" || menu.gameState == "play1"|| menu.gameState == "play2"||menu.gameState == "play3") // all stages display buttons
    {
        
        
        grid.font.drawString("SIMULATION", 20, 45);
        grid.font.drawString("      GAME_1", 320, 45);
        grid.font.drawString("      GAME_2", 620, 45);
        grid.font.drawString("     CREDITS", 920, 45);
        
    }
    
    if (menu.gameState == "play" || menu.gameState == "play1"|| menu.gameState == "play2")
    {
        
        
        grid.display(); // display the grid in the above stages
        
    }
    if (menu.gameState == "play" || menu.gameState == "play1"|| menu.gameState == "play3") // reset queue and stack if starting again
    {
        cheetah.key_moves.setFront(0);
        cheetah.key_moves.setBack(0);
        cheetah.wrong_way.setTop(-1);
        
        
        
    }
    
    
    
    
    
    
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    menu.condition(key); // based on key pressed change the different menu sections
    if(menu.gameState == "play1" && cheetah.over==false)
    {
        rabbit.keyDown(key); // key pressed for rabbit
        rabbit.update_key(); // update key for rabbit
        
    }
    
    if (menu.gameState == "play2") // check for input key in game_2 state
    {
        if(key == 'w')
        {
            up = true;
            right = false;
            left = false;
            down = false;
            start = false;
        }
        else if(key == 's')
        {
            up = false;
            right = false;
            left = false;
            down = true;
            start = false;
        }
        else if(key == 'd')
        {
            up = false;
            right = true;
            left = false;
            down = false;
            start = false;
        }
        else if(key == 'a')
        {
            up = false;
            right = false;
            left = true;
            down = false;
            start = false;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    std::cout << key;
    if( menu.gameState == "play1"&&cheetah.over==false) // release each key input
    {
        rabbit.keyUp(key);
    }
    
    if(menu.gameState == "play2") // same for stage 2
    {
        cheetah.keyDown(key);
        
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    selection(); // calling selection functino to select the game state
    
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
    
}

void ofApp::selection()
{
    // looking at which button is pressed and based on that go to the right selection game stage
    for (int i = 0; i<buttons.size(); i++)
        
    {
        
        if (buttons[0].check() && (menu.gameState == "play" || menu.gameState == "play1" || menu.gameState == "play2" || menu.gameState == "play3"))
        {
            menu.gameState = "play";
            float temp = 40;
            float temp1 = 160;
            float tempc = 1080;
            float temp1c = 720;
            rabbit.setX(temp);
            rabbit.setY(temp1);
            cheetah.setX(tempc);
            cheetah.setY(temp1c);
            cheetah.over=false;
            rabbit.stop= false;
            
        }
        else if (buttons[1].check() && (menu.gameState == "play" || menu.gameState == "play1" || menu.gameState == "play2" || menu.gameState == "play3"))
        {
            menu.gameState = "play1";
            float temp = 40;
            float temp1 = 160;
            float tempc = 1080;
            float temp1c = 720;
            rabbit.setX(temp);
            rabbit.setY(temp1);
            cheetah.setX(tempc);
            cheetah.setY(temp1c);
            cheetah.over=false;
            collectable.score = 0;
            
        }
        else if (buttons[2].check() && (menu.gameState == "play" || menu.gameState == "play1" || menu.gameState == "play2" || menu.gameState == "play3"))
        {
            menu.gameState = "play2";
            
            
        }
        else if (buttons[3].check() && (menu.gameState == "play" || menu.gameState == "play1" || menu.gameState == "play2" || menu.gameState == "play3"))
        {
            menu.gameState = "play3";
        }
    }
    
    
    if(menu.gameState == "play"&& simulation.check())
        
    {
        sim = !sim;
    }
    
    if (menu.gameState == "play2"&&move.check())
    {
        cheetah.mov = true;
        
    }
    if (menu.gameState == "play2"&&pop.check())
    {
        cheetah.popping = true;
        
    }
    
    
    if(menu.gameState == "play1"&& restart1.check()) // if restart then restart all the variables
    {
        
        float temp = 40;
        float temp1 = 160;
        float tempc = 1080;
        float temp1c = 720;
        rabbit.setX(temp);
        rabbit.setY(temp1);
        cheetah.setX(tempc);
        cheetah.setY(temp1c);
        cheetah.over=false;
        collectable.score = 0;
    }
    
    if((menu.gameState == "play2"&& random.check()) || buttons[2].check())// randomise and resetting values
    {
        cheetah.over = false;
        cheetah.key_moves.setFront(0);
        cheetah.key_moves.setBack(0);
        cheetah.wrong_way.setTop(-1);
        up = false;
        right = false;
        left = false;
        down = false;
        start = true;
        
        int randomx = ofRandom(14);
        int randomy = ofRandom(8);
        int randomX = ofRandom(14);
        int randomY = ofRandom(8);
        
        int randomX1 = ofRandom(14);
        int randomY1 = ofRandom(8);
        
        int randomX2 = ofRandom(14);
        int randomY2 = ofRandom(8);
        
        int randomX3 = ofRandom(14);
        int randomY3 = ofRandom(8);
        
        int randomX4 = ofRandom(14);
        int randomY4= ofRandom(8);
        
        int randomX5 = ofRandom(14);
        int randomY5 = ofRandom(8);
        
        if(randomx == randomX)
        {
            randomx = ofRandom(14);
        }
        if(randomy == randomY)
        {
            randomy = ofRandom(8);
        }
        float temp = 40+(80*randomx);
        float temp1 = 160+(80*randomy);
        float tempc = 40+(80*randomX);
        float temp1c = 160+(80*randomY);
        float temp_1 = 40+(80*randomX1);
        float temp_11 = 160+(80*randomY1);
        float temp_2 = 40+(80*randomX2);
        float temp_22 = 160+(80*randomY2);
        float temp_3 = 40+(80*randomX3);
        float temp_33 = 160+(80*randomY3);
        float temp_4 = 40+(80*randomX4);
        float temp_44 = 160+(80*randomY4);
        float temp_5 = 40+(80*randomX5);
        float temp_55 = 160+(80*randomY5);
        rabbit.setX(temp);
        rabbit.setY(temp1);
        cheetah.setX(tempc);
        cheetah.setY(temp1c);
        one.x = temp_1;
        one.y = temp_11;
        two.x = temp_2;
        two.y = temp_22;
        three.x = temp_3;
        three.y = temp_33;
        four.x = temp_4;
        four.y = temp_44;
        five.x = temp_5;
        five.y = temp_55;
    }
    
    
    if(menu.gameState == "play"&& restart.check()) // randomise when pressing random button
        
    {
        int randomx = ofRandom(14);
        int randomy = ofRandom(8);
        int randomX = ofRandom(14);
        int randomY = ofRandom(8);
        
        if(randomx == randomX)
        {
            randomx = ofRandom(14);
        }
        if(randomy == randomY)
        {
            randomy = ofRandom(8);
        }
        float temp = 40+(80*randomx);
        float temp1 = 160+(80*randomy);
        float tempc = 40+(80*randomX);
        float temp1c = 160+(80*randomY);
        rabbit.setX(temp);
        rabbit.setY(temp1);
        cheetah.setX(tempc);
        cheetah.setY(temp1c);
        rabbit.stop = false;
        cheetah.count_moves = 0;
    }
    
}

