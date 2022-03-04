#pragma once
#include "RandomPowerup.h"

RandomPowerup::RandomPowerup(){
    confusedimage.load("images/question mark powerup.png");
    activatable=false;

}

void RandomPowerup::Activate(Player*player){
    player->setRandomLocation();
    activatable=false;
}

void RandomPowerup::keypressed(int key, Player*player){
    switch (key)
    {
    case ' ':
        if (activatable==true){
            Activate(player);
        }
        break;
    }
}

void RandomPowerup::tick(Player*player){
    if (player->getAteRandomGhost()){
        activatable=true;
    }
}

void RandomPowerup::render(){
   if (activatable==true){
    ofSetColor(169,169,169);
    confusedimage.draw(ofGetWidth()-150,ofGetHeight()/2,100,100);
   }
}