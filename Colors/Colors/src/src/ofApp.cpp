#include "ofApp.h"

#include "PointShape.h"
#include "DynamicManager.h"
#include "NewtonPhysics.h"
#include "OFRenderer.h"
#include "Menu.h"

//--------------------------------------------------------------
void ofApp::setup() {
    manager.init(new Menu());
}

//--------------------------------------------------------------
void ofApp::update() {
    manager.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
    manager.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
    manager.mouseMoved(x, y);

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
    manager.mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    manager.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
    manager.mouseReleased(x, y, button);
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
