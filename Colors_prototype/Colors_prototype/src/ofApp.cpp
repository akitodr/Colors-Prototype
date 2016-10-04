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
Menu menu;
vector<Circle*> objects;

//fazendo mta gambiarra pra implementar o menu

//--------------------------------------------------------------
void ofApp::setup() {

	menu.init();

	background.load("img/cenario_cinza_1.jpg");
	player.setup();

	objects.push_back(new Circle());
	objects.push_back(new Circle());
	objects.push_back(new Circle());

	for (int i = 0; i < objects.size(); i++) {
		if(objects[i] != nullptr)
		objects[i]->init();
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	player.update(ofGetLastFrameTime());

	for (int i = 0; i < objects.size(); i++) {
		if (objects[i]->collided(&player)) {
			player.interpolateColor(2, 3);
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255, 255, 255);

	do
	{
		menu.draw();
	} while (!menu.click);

	if (menu.click) {
		background.draw(0, 0);

		for (int i = 0; i < objects.size(); i++) {
			if (objects[i]) { //se o circulo estiver ativo
				if (!objects[i]->collided(&player) && objects[i] != nullptr) { // e não estiver colidindo
					objects[i]->draw(); //desenha
				}
				else { //se estiver colidindo seta false
					objects[i] = nullptr;
				}
			}
		}
		player.draw();
	}
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
	player.setPosition(ofVec2f(x, y));
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
