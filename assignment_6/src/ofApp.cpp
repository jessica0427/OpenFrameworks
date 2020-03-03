#include "ofApp.h"

ofTrueTypeFont myFont1,myFont2;

ofVec2f center;
ofVec2f raincharacter, raindrop, suncharacter, sun ;

ofVec2f button1, button2;
float shrink1,shrink2;

float degrees;

bool drawCircles;
float enlarge,alpha;

ofFbo fbo;
float fading;
bool fkeyPressed;

ofImage raincharacterImage, raindropImage, suncharacterImage, sunImage;

ofSoundPlayer radioSignal;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1200, 700);
    
    fbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    fbo.begin();
    ofClear(0);
    fbo.end();
    
    center.set(ofGetWindowWidth()*0.5,ofGetWindowHeight()*0.5);
    
    earth = center;
    sun.set(ofGetWindowWidth()+100, ofGetWindowHeight()+200);
    degrees = 0;
    
    button1.set(60,120);
    button2.set(60,190);
    shrink1 = 1;
    shrink2 = 1;
    
    drawCircles = false;
    
    ofSetCircleResolution(50);
    
    myFont1.load("fonts/Nunito-SemiBold.ttf", 40);
    
    enlarge = 1.5;
    alpha = 255;
    
    fading = 0;
    
    raincharacterImage.load("images/earth.png");
    raindrop.load("images/raindrop.png");
    suncharacterImage.load("images/suncharacter.png");
    sunImage.load("images/sun.png");
    
    radioSignal.load("sound/Radio Signal Sound Effect.mp3");
}

//--------------------------------------------------------------
void ofApp::update(){
    degrees++;
    
    if(fkeyPressed == true){
        fading += 1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
    ofSetColor(255);
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

    
    if(drawCircles == true){
        ofSetColor(255,alpha);
        ofSetLineWidth(2);
        ofNoFill();
        ofDrawCircle(earth, 10*enlarge);
        ofDrawCircle(earth, 20*enlarge);
        ofDrawCircle(earth, 30*enlarge);
        ofDrawCircle(earth, 40*enlarge);
        ofDrawCircle(earth, 50*enlarge);
        ofDrawCircle(earth, 60*enlarge);
        ofDrawCircle(earth, 70*enlarge);
        
        enlarge += 0.2;
        alpha -= 2;
    }
    
    if(10*enlarge>350){
        drawCircles = false;
        enlarge = 0;
        alpha = 255;
    }
    
    
    ofSetColor(0, 0, 200);
    ofFill();
    //    ofDrawCircle(earth, 80);
    earthImage.draw(earth-80,160,160);
    moon = earth+120;
    orbit = moon.rotate(degrees, earth);
    ofSetColor(150);
    //    ofDrawCircle(orbit, 30);
    moonImage.draw(moon-20,40,40);
    //    ofSetColor(ofColor::orange);
    //    ofDrawCircle(sun, 500);
    sunImage.draw(sun-(500,700));
    
    
    ofSetColor(0);
    myFont1.drawString("Weathering with You",60,70);
    
    ofRectangle b1,b2;
    ofSetColor(200,225);
    b1.x = button1.x+5;
    b1.y = button1.y+5;
    b2.x = button2.x+5;
    b2.y = button2.y+5;
    b1.width = 200*shrink1;
    b1.height = 45*shrink1;
    b2.width = 200*shrink2;
    b2.height = 45*shrink2;
    ofDrawRectRounded(b1, 8);
    ofDrawRectRounded(b2, 8);
    
    b1.x = button1.x;
    b1.y = button1.y;
    b2.x = button2.x;
    b2.y = button2.y;
    ofSetColor(255,225);
    ofDrawRectRounded(b1, 8);
    ofDrawRectRounded(b2, 8);
    
    ofSetColor(0);
    myFont2.load("fonts/RobotoMono-Regular.ttf", 15*shrink1);
    myFont2.drawString("rain", b1.x+10*shrink1, b1.y+30*shrink1);
    myFont2.load("fonts/RobotoMono-Regular.ttf", 15*shrink2);
    myFont2.drawString("sun", b2.x+10*shrink1, b2.y+30*shrink2);
    
    
    ofSetColor(216,106,106,fading);
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    

    fbo.end();
    fbo.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'f'){
        fkeyPressed = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    earth.set(x,y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(ofGetMouseX()>=button1.x && ofGetMouseX()<=(button1.x+200) && ofGetMouseY()>=button1.y && ofGetMouseY()<=(button1.y+45)){
        shrink1*=0.9;
        drawCircles = true;
        
        radioSignal.play();
    }
    if(ofGetMouseX()>=button2.x && ofGetMouseX()<=(button2.x+200) && ofGetMouseY()>=button2.y && ofGetMouseY()<=(button2.y+45)){
        shrink2*=0.9;
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    shrink1 = 1;
    shrink2 = 1;
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