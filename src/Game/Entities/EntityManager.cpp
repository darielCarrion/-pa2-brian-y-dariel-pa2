#include "EntityManager.h"
#include "Ghost.h"
#include "RandomGhost.h"
void EntityManager::tick(){
    if(killable){
        killableCounter--;
        if (killableCounter == 0){
            killable = false;
            for(Entity* entity:ghosts){
                Ghost* ghost = dynamic_cast<Ghost*>(entity); 
                ghost->setKillable(false);
            }
            for (Entity* helpmeghost:randomghostsvector){
                RandomGhost*randomghostboi= dynamic_cast<RandomGhost*>(helpmeghost);
                randomghostboi->setKillable(false);
            }
        }
    }
    std::vector<int> toRemove;
    
    for(int i=0;i<entities.size();i++){
        if(!entities[i]->remove){
            entities[i]->tick();

        }else{
            toRemove.push_back(i);
        }
    }
    for(unsigned int removable: toRemove){
        Entity* entityPointer = *(entities.begin() + removable);
        entities.erase(entities.begin() + removable);
        delete entityPointer;
    }
    toRemove.clear();
    for(BoundBlock* BoundBlock: BoundBlocks){
        BoundBlock->tick();
    }
    for(int i=0;i<ghosts.size();i++){
        if(!ghosts[i]->remove){
            ghosts[i]->tick();

        }else{
            toRemove.push_back(i);
        }
    }
    for(unsigned int removable: toRemove){
        Ghost* entityPointer = dynamic_cast<Ghost*>(*(ghosts.begin() + removable));
        ghosts.erase(ghosts.begin() + removable);
        delete entityPointer;
    }
    toRemove.clear();
    for(int i=0;i<randomghostsvector.size();i++){
        if(!randomghostsvector[i]->remove){
            randomghostsvector[i]->tick();

        }else{
            toRemove.push_back(i);
        }
    }
    for(unsigned int removable: toRemove){
        RandomGhost* entityPointer = dynamic_cast<RandomGhost*>(*(randomghostsvector.begin() + removable));
        randomghostsvector.erase(randomghostsvector.begin() + removable);
        delete entityPointer;
    }
}

void EntityManager::render(){
    for(Entity* entity: entities){
        entity->render();
    }
    for(BoundBlock* BoundBlock: BoundBlocks){
        BoundBlock->render();
    }
    for(Entity* ghost: ghosts){
        ghost->render();
    }
    for (Entity* helpmeghost:randomghostsvector){
        helpmeghost->render();
    }
}

void EntityManager::setKillable(bool k){
    killable = true;
    killableCounter=30*10;
    for(Entity* entity:ghosts){
        Ghost* ghost = dynamic_cast<Ghost*>(entity); 
        ghost->setKillable(true);
    }
    for (Entity* helpmeghost:randomghostsvector){
        RandomGhost* randomghostboi = dynamic_cast<RandomGhost*>(helpmeghost);
        randomghostboi->setKillable(true);
    }
}

EntityManager::~EntityManager(){
    for(Entity* e: BoundBlocks){
        delete e;

    }
    for(Entity* e: ghosts){
        Ghost* ghostPointer = dynamic_cast<Ghost*>(e);
        delete e;
    }
    for(Entity* e: entities){
        delete e;
    }
    BoundBlocks.clear();
    ghosts.clear();
    entities.clear();
}