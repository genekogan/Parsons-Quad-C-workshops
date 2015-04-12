#pragma once

#include "ofMain.h"
#include "ofxFluid.h"
#include "ofxKinect.h"
#include "ofxCv.h"


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxFluid fluid;
    
    ofxKinect kinect;
    ofxCv::ContourFinder contourFinder;

    
    vector<vector<cv::Point> > prevPoints;
    
    int skip;
    float magnitude;
    
};
