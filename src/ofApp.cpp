#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    nPts= 0.0;
    xcolor = 1.0;
    ycolor = 1.0;

    soundStream.setup(this, MY_CHANNELS, MY_CHANNELS, MY_SRATE, MY_BUFFERSIZE, MY_NBUFFERS);
    
    left.resize( MY_BUFFERSIZE, 0 );
    right.resize( MY_BUFFERSIZE, 0 );
    
    // Initialize faust
    synth.init(MY_SRATE);
    synth.buildUserInterface(&synthControl); // linking the Faust module to the controler


    for(int i=0; i<synthControl.getParamsCount(); i++){
        std::cout << synthControl.getParamAdress(i) << "\n";
    }


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(100*xcolor, 60*ycolor, 100*ycolor);
    if (nPts > 1) {
        for(int i = 0; i< nPts - 1; i++) {
            ofLine(pts[i].x,pts[i].y,pts[i+1].x,pts[i+1].y);
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    //std::cout << y << "\n";

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if (nPts < MAX_PTS)
    {
        pts[nPts].x=x;
        pts[nPts].y=y;
        nPts++;
        xcolor = 1000.0/x;
        ycolor = 1000.0/y;
//        std::cout << xcolor << "\n";

    }
    
    synthControl.setParamValue("/saw/freq", 300 + y);
    synthControl.setParamValue("/saw/fc_lp", 300 + x);


}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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

void ofApp::audioOut(float * output, int bufferSize, int nChannels) {
    // Interleave the output buffer
    float *buf[2] = {&left[0], &right[0]};
    
    synth.compute(bufferSize, NULL, buf);
    
    for (int i = 0; i < MY_BUFFERSIZE; i++)
    {
        output[2*i] = left[i]; //audioBuffer[0][i];
        output[2*i+1] = right[i]; //audioBuffer[1][i];
    }
}
