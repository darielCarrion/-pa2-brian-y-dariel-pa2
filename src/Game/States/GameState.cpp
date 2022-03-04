#include "GameState.h"
#include "Entity.h"

GameState::GameState() {
	music.load("music/pacman_chomp.wav");
	mapImage.load("images/map1.png");
	map = MapBuilder().createMap(mapImage);
	pausestate= new PauseState();
	randompowerup= new RandomPowerup();
}
void GameState::tick() {
	if(!music.isPlaying()){
			music.play();
	}
	if (!pausestate->isPaused()){
		map->tick();
	}
	else {
		music.stop();
	}
	if(map->getPlayer()->getHealth() == 0){
		setFinished(true);
		setNextState("over");
		map->getPlayer()->setHealth(3);
		finalScore = map->getPlayer()->getScore();
		map->getPlayer()->setScore(0);
	}
	else 	if(map->getPlayer()->getScore()==4400){
		setFinished(true);
		setNextState("win");
		map->getPlayer()->setHealth(3);
		finalScore = map->getPlayer()->getScore();
		map->getPlayer()->setScore(0);
	}
	else if (pausestate->getquit()->wasPressed()){
		setNextState("Menu");
		setFinished(true);
		map->getPlayer()->setScore(0);
		map->getPlayer()->setHealth(3);
		pausestate->setPause(false);
	}
	pausestate->tick();
	randompowerup->tick(map->getPlayer());
}
void GameState::render() {
	map->render();
	if (pausestate->isPaused()){
		pausestate->render();
	}
	randompowerup->render();
}

void GameState::keyPressed(int key){
	map->keyPressed(key);
	pausestate->keyPressed(key);
	randompowerup->keypressed(key, map->getPlayer());

}

void GameState::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
	pausestate->mousePressed(x, y, button);
}

void GameState::keyReleased(int key){
	map->keyReleased(key);
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
	mapImage.load("images/map1.png");
	map = MapBuilder().createMap(mapImage);
	pausestate->reset();}

int GameState::getFinalScore(){
	return finalScore;
}

GameState::~GameState(){
	delete map;
}