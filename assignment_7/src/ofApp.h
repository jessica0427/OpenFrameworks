#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	 

	public:
		void setup();
		void update();
		void draw();

        void drawFace(int x, int y);
        void drawHappyParts(int x, int y);
        void drawSadParts(int x, int y);
        void drawSurprisedParts(int x, int y);
        void drawAngryParts(int x, int y);

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

         void emotionchanged();
        void scaleFace(int & face);
        void playSound(int sd);
        
        //An ofxFloatSlider to control the sound volume
        ofxFloatSlider volume;
        ofxFloatSlider rotate;
        //An ofxButton to rotate between which emotion is being displayed
        ofxButton emotion;
        //An ofxVec2Slider to change the x,y of all shapes being drawn
        ofxVec2Slider center;
        //An ofxColorSlider to select the color of one shape in the drawing
        ofxColorSlider color;
        //An ofxIntSlider shape movement (degree of emotion) 一个 xintslider
        ofxIntSlider face;
        
        ofxPanel gui;

        ofSoundPlayer sound;
        
       
        
    
  
};
		
};