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
#include "Collectibles.h"

Player player;
Circle circle;

//--------------------------------------------------------------
void ofApp::setup() {
	background.load("img/cenario_cinza_1.jpg");
	player.setup();
	circle.init();
}

//--------------------------------------------------------------
void ofApp::update() {
	player.update(ofGetLastFrameTime());
	circle.collided(&player);
}

//--------------------------------------------------------------
void ofApp::draw() {
	background.draw(0, 0);
	if (circle.active) { //se o circulo estiver ativo
		if (!circle.collided(&player)) { // e não estiver colidindo
			circle.draw(); //desenha
		}
		else { //se estiver colidindo seta false
			circle.active = false;
		}
	}
	player.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == GLFW_KEY_SPACE) {
		player.interpolateColor(0, 50);
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
