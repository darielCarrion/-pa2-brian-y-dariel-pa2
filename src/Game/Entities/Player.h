#pragma once
#include "Animation.h"

#include "EntityManager.h"

class Player: public Entity{// public Powerup{ 

    private:
        int Powerup = 0;
        int spawnX, spawnY;
        int health=3;
        int score=0;
        bool canMove;
        int speed = 8;
        bool walking = false;
        bool aterandomghost=false;
        bool ateghost=false;
        bool atepeekabooghost=false;
        FACING facing = DOWN;
        ofImage up, down, left, right;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        EntityManager* em;
        // RandomPowerup* randompowerup;

    public:
        Player(int, int, int , int, EntityManager*);
        ~Player();
        int getHealth();
        void setHealth(int);
        int getScore();
        void setScore(int);
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void damage(Entity* damageSource);
        void mousePressed(int, int, int);
        void reset();
        void setFacing(FACING facing);
        void checkCollisions();
        void die();
        int Getx();
        int Gety();
        void setx(int x);
        void sety(int y);
        bool getAteghost();
        bool getAteRandomGhost();
        bool getAtePeekaBooGhost();
        void setRandomLocation();
        // void otherrender();
        // void tick(Player*);
        // void keypressed(int key, Player*);
};