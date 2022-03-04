#pragma once
#include "ofMain.h"
#include "Player.h"

class Powerup{
    public:
    virtual void Activate(Player) = 0;
    virtual void render()=0;
    virtual void tick(Player)=0;
    virtual void keypressed(int key, Player*)=0; 
    bool activatable;
    bool activated;
    ofImage confusedimage; 
    private:

};