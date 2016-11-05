#include "ofApp.h"

#include "PointShape.h"
#include "DynamicManager.h"
#include "NewtonPhysics.h"
#include "OFRenderer.h"
#include "Screen.h"

using namespace math;
using namespace particle;
using namespace particle::physics;
using namespace particle::body;
using namespace particle::manager;
using namespace particle::shape;



ofVec2f mousePressedPos;
ofVec2f mousePos;
bool mouseDown = false;

//fazendo mta gambiarra pra implementar o menu

//--------------------------------------------------------------
void ofApp::setup() {

	

}

//--------------------------------------------------------------
void ofApp::update() {
    float secs = ofGetLastFrameTime();



}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(215, 155, 155);
	

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

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
