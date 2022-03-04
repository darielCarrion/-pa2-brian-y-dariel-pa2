#include "GhostSpawner.h"
#include "Ghost.h"
#include "Dot.h"
#include "RandomGhost.h"
GhostSpawner::GhostSpawner(int x, int y, int width, int height, EntityManager* em, ofImage sprite) : Entity(x, y, width, height){
    this->em = em;
    this->sprite = sprite;
    spawnGhost("red");
    spawnGhost("pink");
    spawnGhost("cyan");
    spawnGhost("orange");

}

void GhostSpawner::tick(Player*player){
    std::vector<string> colors;
    colors.push_back("red");
    colors.push_back("pink");
    colors.push_back("cyan");
    colors.push_back("orange");

    if(em->ghosts.size()<4){
        if(spawnCounter == 0){
            spawnGhost(colors[ofRandom(4)]);
            spawnCounter = 30*5;
        }else{
            spawnCounter--;
        }
    }
    if(player->getScore()>=500&& em->randomghostsvector.size()==0){
        spawnRandGhost(colors[ofRandom(4)],player);
    }
    // if(player->getScore()%50==0&& ){
    //     spawnRandGhost(colors[ofRandom(4)],player);
    // }
}
void GhostSpawner::spawnGhost(string color){
    Ghost* g = new Ghost(x,y,width-2,height-2,sprite,em, color);
    em->ghosts.push_back(g);
}

void GhostSpawner::spawnRandGhost(string color, Player*player){
    Dot* dot = dynamic_cast<Dot*>(em->entities[ofRandom(em->entities.size())]);

    bool close=true;
    while(close==true){
        close=false;
         while(dot==NULL){
            dot = dynamic_cast<Dot*>(em->entities[ofRandom(em->entities.size())]);
         }
        for(int i=-80;i<=80;i++){
            for(int a=-80;a<=80;a++){
                if(player->Getx()+i==dot->getx()&&player->Gety()+a==dot->gety()){
                    close= true;
                }
            }
        }
    }
    Entity* confusedghost=new RandomGhost(dot->getx(),dot->gety(),width-2,height-2,sprite,em, color);
    em->randomghostsvector.push_back(confusedghost);
}

void GhostSpawner::keyPressed(int key){
    if(key == 'g'){
        spawnGhost("red");
    }
}