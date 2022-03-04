#pragma once
#include "State.h"
#include "Player.h"
#include "MapBuilder.h"
#include "PauseState.h"
#include "Winstate.h"
#include "RandomPowerup.h"
class GameState: public State{
    public: 
        GameState();
		~GameState();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);
		int getFinalScore();
		RandomPowerup*randompowerup;
	
	private:
		ofSoundPlayer music;
		ofImage mapImage;
		Map* map;
		int finalScore=0;
		PauseState* pausestate;
		
};