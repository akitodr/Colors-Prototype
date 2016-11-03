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
#include "Camera.h"
#include "Flower.hpp"


Player player;
Camera camera;
Flower flower;
//Menu menu;
vector<Circle*> objects;

ofVec2f mousePressedPos;
ofVec2f mousePos;
bool mouseDown = false;

//fazendo mta gambiarra pra implementar o menu

//--------------------------------------------------------------
void ofApp::setup() {

	//menu.init();
	background.load("img/cenario_cinza_2.jpg");
	camera.Init(ofVec2f(background.getWidth(), background.getHeight()));
	player.setup();
    flower.init();

	for (int i = 0; i < 20; i++) {
		objects.push_back(new Circle());
	}

	for (int i = 0; i < objects.size(); i++) {
		if (objects[i] != nullptr)
			objects[i]->init();
	}
	player.setPosition(ofVec2f(background.getWidth() / 2, background.getHeight() / 2));
    
    

}

//--------------------------------------------------------------
void ofApp::update() {
    float secs = ofGetLastFrameTime();

	camera.Update(player.getPosition());
	player.update(secs);
    flower.update(player.getPosition(),secs);

	//interpolação de cor do objeto
	for (int i = 0; i < objects.size(); i++) {
		if (objects[i] && objects[i]->collided(&player)) {
			player.interpolateColor(objects[i]->color, 50);
			objects[i] = nullptr;
		}
	}

	//movimentando o player com o mouse clicado
	if (mouseDown) {
		player.setDirection(mousePos - mousePressedPos);
	}
	else {
		player.setDirection(ofVec2f());
	}


}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(215, 155, 155);
	background.draw(-camera.getPosition());
    flower.draw(camera.getPosition());


	for (int i = 0; i < objects.size(); i++) {
		if (objects[i]) { //se o circulo estiver ativo
			objects[i]->draw(camera.getPosition()); //desenha
		}
	}
	player.draw(camera.getPosition());
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

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	mousePos.set(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	mousePressedPos.set(x, y);
	mousePos.set(x, y);
	mouseDown = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	mouseDown = false;
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
