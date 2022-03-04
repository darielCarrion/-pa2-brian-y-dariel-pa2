#pragma once

#include "EntityManager.h"
#include "Player.h"
class GhostSpawner: public Entity{
    public:
        GhostSpawner(int, int, int , int, EntityManager*, ofImage);
        void spawnGhost(string);
        void spawnRandGhost(string, Player*);
        void keyPressed(int);
        void tick(Player*);
    private:
        EntityManager* em;
        int spawnCounter = 30*5;
};