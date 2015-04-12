#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    fluid.allocate(ofGetWidth(), ofGetHeight(), 0.5);
    fluid.dissipation = 0.99;
    fluid.velocityDissipation = 0.99;

    fluid.setGravity(ofVec2f(0.0,0.0));
    
    fluid.begin();
    ofSetColor(0,0);
    ofSetColor(255);
    ofCircle(ofGetWidth()*0.5, ofGetHeight()*0.35, 100);
    fluid.end();
    fluid.setUseObstacles(false);

    fluid.addConstantForce(ofPoint(ofGetWidth()*0.5,ofGetHeight()*0.85), ofPoint(0,-2), ofFloatColor(0.5,0.1,0.0), 10.0);

}

//--------------------------------------------------------------
void ofApp::update(){

    // m is the position of the mouse
    // d is the vector of the mouse's direction
    // color is the initial color of the force
    // a temporal force acting on the flame instantaneously
    
    ofPoint m = ofPoint(ofGetMouseX(),ofGetMouseY());
    ofPoint d = ofPoint(ofGetMouseX() - ofGetPreviousMouseX(), ofGetMouseY() - ofGetPreviousMouseY()) * 10.0;
    ofFloatColor color = ofFloatColor(1.0, 1.0, 1.0)*sin(ofGetElapsedTimef());
    fluid.addTemporalForce(m, d, color, 3.0f);

    
    fluid.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    fluid.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
