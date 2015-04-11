#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    
    img.loadImage("fawkes.png");
    
    ofSetVerticalSync(true);
    ofSetFrameRate(120);
    finder.setup("haarcascade_frontalface_default.xml");
    finder.setPreset(ObjectFinder::Fast);
    cam.initGrabber(640, 480);
}

void ofApp::update() {
    cam.update();
    if(cam.isFrameNew()) {
        finder.update(cam);
    }
}

void ofApp::draw() {
    cam.draw(0, 0);
    
    for (int i=0; i<finder.size(); i++) {
        ofRectangle r = finder.getObject(0);
        
        img.draw(r.x, r.y, r.width, r.height);
    }
    
}
