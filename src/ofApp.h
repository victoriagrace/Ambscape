#pragma once

#include "ofMain.h"
#include "drawSynth.h"

// Preprocessor definitions
//-----------------------------------------------------------------------------
#define MY_SRATE         44100            // sample rate
#define MY_CHANNELS      2                // number of channels
#define MY_BUFFERHISTORY 72               // number of buffers to save
#define MY_BUFFERSIZE    512              // number of frames in a buffer
#define MY_NBUFFERS      2                // number of buffers latency
#define MY_PIE           3.14159265358979 // for convenience
#define N_BINS           MY_BUFFERSIZE / 2

#define MAX_PTS 3000

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		 
    
    void audioOut(float * input, int bufferSize, int nChannels);
    
    //------------------- for Faust reverb stuff!
    float **audioBuffer; // The 2d audio buffer that Faust wants to work with
    

    ofPoint pts[MAX_PTS];
    int nPts;
    float xcolor;
    float ycolor;
    
    drawSynth synth;
    MapUI synthControl; // used to easily control the Faust module (Reverb.h)
    
    ofMutex myMutex;
    ofNode node;
    
    // Our sound stream object
    ofSoundStream soundStream;
    
    
    private:
    
    
    // Vectors for our left- and right-channel waveforms
    vector<float> left;
    vector<float> right;
    
};
