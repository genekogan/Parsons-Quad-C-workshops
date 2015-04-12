#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    
    kinect.setRegistration(true);
    kinect.init();
    kinect.open();

    fluid.allocate(640, 480, 0.5);
    fluid.dissipation = 0.99;
    fluid.velocityDissipation = 0.99;
    
    fluid.setGravity(ofVec2f(0.0,0.0));
    
    fluid.begin();
    ofSetColor(0,0);
    ofSetColor(255);
    ofCircle(640*0.5, 480*0.35, 100);
    fluid.end();
    fluid.setUseObstacles(false);
    
    fluid.addConstantForce(ofPoint(640*0.5,480*0.85), ofPoint(0,-2), ofFloatColor(0.5,0.1,0.0), 10.0);
    
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

    skip = 20;
    magnitude = 5;

    vector<vector<cv::Point> > newPrevPoints;
    
    int numContours = contourFinder.size();
    for (int i=0; i<numContours; i++) {
        vector<cv::Point> points = contourFinder.getContour(i);
        newPrevPoints.push_back(points);
        
        for (int j=0; j<points.size(); j+=skip)
        {
            if (i < prevPoints.size() && j < prevPoints[i].size()) {
                ofPoint m = ofPoint(points[j].x, points[j].y);
                ofPoint d = ofPoint(points[j].x - prevPoints[i][j].x, points[j].y - prevPoints[i][j].y) * magnitude;
                ofFloatColor color = ofFloatColor(1.0, 1.0, 1.0) * sin(0.1*ofGetFrameNum());
                fluid.addTemporalForce(m, d, color, 3.0f);
            }
        }
    }

    prevPoints = newPrevPoints;
    
    
    fluid.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofScale(ofGetWidth() / 640.0, ofGetHeight() / 480.0);
    
    fluid.draw();
    
    ofSetColor(255, 255, 0);
    ofNoFill();
    ofSetLineWidth(2);
    
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
