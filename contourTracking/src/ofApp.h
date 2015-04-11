#pragma once

#include "ofMain.h"
#include "ofxCv.h"

using namespace ofxCv;

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    
    ofVideoGrabber cam;
    ofxCv::RunningBackground background;
    ofImage thresholded;
    
    ofVideoPlayer player;
    
    ContourFinder finder;
};
