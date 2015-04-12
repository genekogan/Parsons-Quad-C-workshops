#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 960);

    kinect.setRegistration(true);
    kinect.init();
    kinect.open();
}

void ofApp::exit(){
    kinect.close();
}

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update();

    if (kinect.isFrameNew()) {
        contourFinder.setThreshold(ofMap(mouseX, 0, ofGetWidth(), 0, 255));
        contourFinder.findContours(kinect.getDepthPixelsRef());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    kinect.drawDepth(0, 0);
    
    ofSetColor(255, 255, 0);
    ofFill();
    ofSetLineWidth(4);
    
    int numContours = contourFinder.size();
    for (int i=0; i<numContours; i++) {
        vector<cv::Point> points = contourFinder.getContour(i);
        ofBeginShape();
        for (int j=0; j<points.size(); j++) {
            ofVertex(points[j].x, points[j].y);
        }
        ofEndShape();
    }
    
    ofSetColor(255);
    
    
    
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
