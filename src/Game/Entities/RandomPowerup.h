#pragma once
#include "PowerUp.h"
#include "Player.h"
class RandomPowerup: Powerup{
    public:
    RandomPowerup();
    ~RandomPowerup();
    void Activate(Player*);
    void render();
    void tick(Player*);
    void keypressed(int key, Player*);
    private:

};
