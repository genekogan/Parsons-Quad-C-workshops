#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    ofSetWindowShape(1280, 480);
    ofSetVerticalSync(true);
    cam.initGrabber(320, 240);
    
    // imitate() will set up previous and diff
    // so they have the same size and type as cam
    imitate(previous, cam);
    imitate(diff, cam);
}

void ofApp::update() {
    cam.update();
    if(cam.isFrameNew()) {
        // take the absolute difference of prev and cam and save it inside diff
        absdiff(previous, cam, diff);
        diff.update();
        
        // like ofSetPixels, but more concise and cross-toolkit
        copy(cam, previous);
        
        // this is the key line: get the average of each column
        columnMean = meanCols(diff);
    }
}

void ofApp::draw() {
    ofBackground(255);
    ofSetColor(255, 0, 0, 50);
    
    thresh = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 30);
    
    for(int i = 0; i < columnMean.rows; i++)
    {
        int x = ofMap(i, 0, columnMean.rows, 0, ofGetWidth());
        
        Vec3b cur = columnMean.at<Vec3b>(i);
        
        for (int c = 0; c < 3; c++) {
            if (cur[c] > thresh) {
                if (c==0)   ofSetColor(255, 0, 0, 30);
                else if (c==1)  ofSetColor(0, 255, 0, 30);
                else if (c==2)  ofSetColor(0, 0, 255, 30);
                
                ofRect(x, 0, 10, ofGetHeight());
            }
        }
    }
}
