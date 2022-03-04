#include "PauseState.h"

PauseState::PauseState() {
	resumeButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50,"" );
    exitButton = new Button(ofGetWidth()/2, ofGetHeight()/2+50, 64, 50,"" );
	resumeimage.load("images/resume button.png");
	quitimage.load("images/quit button.png");
}
void PauseState::tick() {
	resumeButton->tick();
    exitButton->tick();

	if(resumeButton->wasPressed()){
		wantstopause=false;

	}

}
void PauseState::render() {
	
	resumeButton->render();
	exitButton->render();
	ofSetColor(169,169,169);
	resumeimage.draw(ofGetWidth()/2, ofGetHeight()/2, 64, 50);
	quitimage.draw(ofGetWidth()/2, ofGetHeight()/2+50, 64, 50);
}

void PauseState::keyPressed(int key){
	switch (key)
	{
	case 'p':
		wantstopause=true;
		break;

	}
}

void PauseState::mousePressed(int x, int y, int button){
	resumeButton->mousePressed(x, y);
	exitButton->mousePressed(x, y);
}

void PauseState::reset(){
	exitButton->reset();
	resumeButton->reset();
}



PauseState::~PauseState(){
	delete resumeButton;

}
bool PauseState::isPaused(){
	return wantstopause;
}
void PauseState::setPause(bool i){
	wantstopause=i;
}
Button* PauseState::getquit(){
	return exitButton;
}