#include "ofApp.h"

#include "PointShape.h"
#include "DynamicManager.h"
#include "NewtonPhysics.h"
#include "OFRenderer.h"

using namespace math;
using namespace particle;
using namespace particle::physics;
using namespace particle::body;
using namespace particle::manager;
using namespace particle::shape;

#include "Player.h"
#include "Menu.h"
#include "Collectibles.h"


Player player;
//Menu menu;
vector<Circle*> objects;
ofVec2f posCamera;

//fazendo mta gambiarra pra implementar o menu

//--------------------------------------------------------------
void ofApp::setup() {

	//menu.init();

	background.load("img/cenario_cinza_1.jpg");
	player.setup();

	for (int i = 0; i < 20; i++) {
		objects.push_back(new Circle());
	}

	for (int i = 0; i < objects.size(); i++) {
		if (objects[i] != nullptr)
			objects[i]->init();
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	player.update(ofGetLastFrameTime());

	//movimentação de tela
	ofVec2f SCREEN_CENTER(ofGetWidth() / 2, ofGetHeight() / 2);

	posCamera = player.getPosition();
	posCamera -= SCREEN_CENTER;
	//na real aqui não to sabendo o que setar direito
	if (posCamera.x <= 0) {
		posCamera.x = 0;
	}
	else if (posCamera.x >= background.getWidth() - SCREEN_CENTER.x) {
		posCamera.x = background.getWidth() - SCREEN_CENTER.x;
	}

	//interpolação de cor do objeto
	for (int i = 0; i < objects.size(); i++) {
		if (objects[i] && objects[i]->collided(&player)) {
			player.interpolateColor(objects[i]->color, 50);
			objects[i] = nullptr;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255, 255, 255);

	//if (menu.click) {
	background.draw(0 - posCamera.x, 0 - posCamera.y);

	for (int i = 0; i < objects.size(); i++) {
		if (objects[i]) { //se o circulo estiver ativo
			objects[i]->draw(posCamera); //desenha
		}
	}
	player.draw();
	//}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == GLFW_KEY_SPACE) {

	}
	else if (key == 'r')
		player.interpolateColor(0, 50);
	else if (key == 'g')
		player.interpolateColor(1, 50);
	else if (key == 'b')
		player.interpolateColor(2, 50);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	player.setPosition(ofVec2f(x, y) - posCamera);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
