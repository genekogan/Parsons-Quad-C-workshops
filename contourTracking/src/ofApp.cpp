#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    ofSetWindowShape(1280, 960);
    
    cam.initGrabber(640, 480);
    
    player.loadMovie("/Users/gene/Desktop/Parsons/cvVideos/Swarm_EindhovenTest_Watec_heavy-occlusion.mov");
    player.play();
    
    background.setLearningTime(900);
    background.reset();
    
    finder.setMinArea(2);
    finder.setMaxArea(320 * 240 / 3);
}

void ofApp::update() {
    int thresh = ofMap(mouseX, 0, ofGetWidth(), 0, 255);
    background.setThresholdValue(thresh);
    
    cam.update();
    if (cam.isFrameNew()) {
        background.update(cam, thresholded);
        thresholded.update();
        finder.findContours(thresholded);
    }
}

void ofApp::draw() {
    ofSetColor(255, 255);
    
    
    cam.draw(0, 0);
    thresholded.draw(640, 0);
    
    
    int numContours = finder.size();
    
    for (int c = 0; c < numContours; c++)
    {
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        ofFill();

        vector<cv::Point> points = finder.getContour(c);
        
        ofBeginShape();
        for (int i=0; i<points.size(); i++) {
            ofVertex(points[i].x, points[i].y);
        }
        ofEndShape();
    }
    
}

void ofApp::keyPressed(int key) {
    if(key == ' ') {
        background.reset();
    }
}