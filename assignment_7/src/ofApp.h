  
#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
    
        void mouth();
        void mouth2();
        void setXMouth(int m,int n,int p, int q);
        void setYMouth(int m,int n,int p, int q);
    
        void eyes();
        void seteyes(int m, int n);
        
        void eyebrows1();
        void eyebrows2();
        void setXEyebrows(int m,int n,int p, int q);
        void setYEyebrows(int m,int n,int p, int q);
    
        void happiness();
        void sad();
        void surprise();
        void anger();

        
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
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