#include "ofApp.h"

//eyes
int eyeDistanceX = 40;
int eyeDistanceY = 2;
int eyeSize = 12;

//Speed
float s=0.05f;

//point1,2
ofVec2f g1,f1,m1,m2,m3,m4;
ofVec2f eye,eyebrow;
ofVec2f eb1,eb2,eb3,eb4;

//emotion
int x;
float fradius=100;
int sd;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(51,204,204);
    ofSetFrameRate(50);
    ofSetWindowTitle("Week6Assignment");
    // line
    ofSetColor(255);
    ofSetLineWidth(5);
    ofSetCircleResolution(50);
    ofSetCurveResolution(50);
    
    //Center
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    
    //setup point
    g1.set(-30,-30);
    eye.set(50,-20);
    eyebrow.set(40,-90);
    
    m1.set(-70,120);//70,20
    m2.set(-50,120);//50,85
    //sad x:-60,-50,40,50 y:30,25,10,20
    m3.set(50,85);
    m4.set(70,20);
    
    //eyebrow
    eb1.set(40,-90);
    eb2.set(35,-95);
    eb3.set(25,-95);
    eb4.set(20,-90);
    f1.set(80,-40);
//----------------------------------------------------------
//Gui
    ofSetVerticalSync(true);
    
    //Add listenr
    //emotion.addListener(<#ListenerClass *listener#>, <#ListenerMethod method#>)
    emotion.addListener(this, &ofApp::emotionchanged);
    face.addListener(this, &ofApp::scaleFace);
    
    //Gui SETUP
    gui.setup();
    gui.add(face.setup("Scale the Face",100,80,200));
    gui.add(volume.setup("Volume",0.5f,0.0f,1.0f));
    gui.add(rotate.setup("Rotate one eyebrow",10.0f,-10.0f,30.0f));
    //ofxVec2Slider to change the x,y
    //x:x+35  0->40 -20->20
    //y:y=y
    gui.add(center.setup("Move eyes",{0, -5}, {-20, -20}, {30, 10}));
    
    //Button to change emotion
    gui.add(emotion.setup("Change Emotion"));
    //slider to change the color of background
    gui.add(color.setup("background color",ofColor(51,204,204),ofColor(0,0),ofColor(255,255)));
    
    //sound
    sound.load("sound.wav");
        
  
}

//--------------------------------------------------------------
void ofApp::update(){
    
}



//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    ofBackground(color);
    gui.draw();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    //ofTranslate(center->x, center->y);

    //Face
    ofFill();
    ofSetColor(255);
    ofDrawCircle(0, 0, fradius);
    ofSetColor(0, 0, 0 );
    ofDrawCircle(0, 0, fradius-5);
    ofSetColor(51,204,204);
    ofNoFill();

    //line color
    ofSetColor(255);

    //left eye
   ofSetColor(black);
   ofDrawCircle(x - eyeDistanceX , y - eyeDistanceY , eyeSize);

   //right eye
   ofDrawCircle(x + eyeDistanceX , y - eyeDistanceY , eyeSize);

    //volume
    sound.setVolume(volume);
        switch (x) {
        //happiness
        //--------------------------------------------------------------
        case 0:
                //Move eyebrow
                setXEyebrows(40, 35, 25, 20);
                setYEyebrows(-50, -55, -55, -50);
                ofPushMatrix();
                ofRotateZ(rotate);
                eyebrows2();
                ofPopMatrix();
                
                
                
                
                eyebrows1();
                
                
                //mouth ofDrawBezier(-70, 20, -50, 85, 50, 85, 70, 20);
                m1.x+=s*(-70-m1.x);
                m2.x+=s*(-70-m2.x);
                m1.y+=s*(20-m1.y);
                m2.y+=s*(85-m2.y);
                
                eyes();
                
                mouth();
                playSound(0);
            
            break;
        //sad
        case 1:
                //mouth
                //sad x:-60,-50,40,50 y:30,25,10,20
                setXMouth(-60, -50, 40, 50);
                setYMouth(30,25, 10, 20);
                
                //eyebrow
                //x:80,75,50,20
                //y:-10,-13,-15,-40
                setXEyebrows(80, 75, 50, 20);
                setYEyebrows(-10, -13, -15, -40);
                
                eyes();
                eyebrows1();
                eyebrows2();
                mouth2();
                playSound(1);
            break;
        //surprise
        case 2:
                //eyes
                //seteyes(45, -10);
                f1.x+=s*(45-f1.x);
                f1.y+=s*(-10-f1.y);
               
                ofFill();
                ofDrawCircle(f1.x, f1.y, 30);
                ofDrawCircle(f1.x*-1, f1.y, 30);
                ofSetColor(0, 0, 0);
                ofDrawCircle(f1.x, f1.y, 25);
                ofDrawCircle(f1.x*-1, f1.y, 25);
                ofNoFill();
                ofSetColor(255);
                    
                //mouth
                setXMouth(-30, -10, 10 , 20);
                setYMouth(55, 50, 45, 40);
                
                eyes();
                mouth2();
                playSound(2);
            break;
       //anger
        case 3:
                //eye
                //seteyes(35, 0);
                eyes();
                //eyebrow
                setXEyebrows(80, 60, 40, 20);
                setYEyebrows(-40, -35, -30, -10);
                eyebrows1();
                eyebrows2();
                //
                setXMouth(-15,-5, 5, 15);
                setYMouth(45, 20, 20, 45);
                mouth2();
                playSound(3);
            break;
            
        default:
            break;
    }
        
        
    }


//--------------------------------------------------------------
void ofApp::emotionchanged(){
    if (x==3) {
        x=0;
    }
    else  {
        x++;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

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
void ofApp::happiness(){
    //eyes
    eyes();
    eyebrows1();
    mouth();
}
void ofApp::sad(){
    eyes();
    eyebrows1();
    eyebrows2();
    mouth2();
}
void ofApp::surprise(){
    eyes();
    ofDrawCircle(f1.x, f1.y, 30);
    ofDrawCircle(f1.x*-1, f1.y, 30);
    mouth2();
}
void ofApp::anger(){
    eyes();
    eyebrows1();
    eyebrows2();
    mouth2();
}

void ofApp::mouth(){
    ofDrawBezier(m1.x,m1.y,m2.x,m2.y,m2.x*-1,m2.y,m1.x*-1,m1.y);
}

void ofApp::mouth2(){
    ofDrawBezier(m1.x,m1.y,m2.x,m2.y,m3.x,m3.y,m4.x,m4.y);
}
void ofApp::eyebrows1(){
    
    ofDrawBezier(eb1.x*-1,eb1.y,eb2.x*-1,eb2.y,eb3.x*-1,eb3.y,eb4.x*-1,eb4.y);
}
void ofApp::eyebrows2(){
    
    ofDrawBezier(eb1.x,eb1.y,eb2.x,eb2.y,eb3.x,eb3.y,eb4.x,eb4.y);
}

void ofApp::setXEyebrows(int m,int n,int p, int q){
    eb1.x+=s*(m-eb1.x);
    eb2.x+=s*(n-eb2.x);
    eb3.x+=s*(p-eb3.x);
    eb4.x+=s*(q-eb4.x);
}

void ofApp::setYEyebrows(int m,int n,int p, int q){
    eb1.y+=s*(m-eb1.y);
    eb2.y+=s*(n-eb2.y);
    eb3.y+=s*(p-eb3.y);
    eb4.y+=s*(q-eb4.y);
    
}
void ofApp::setXMouth(int m,int n,int p, int q){
    
    m1.x+=s*(m-m1.x);
    m2.x+=s*(n-m2.x);
    m3.x+=s*(p-m3.x);
    m4.x+=s*(q-m4.x);
}
void ofApp::setYMouth(int m,int n,int p, int q){
    m1.y+=s*(m-m1.y);
    m2.y+=s*(n-m2.y);
    m3.y+=s*(p-m3.y);
    m4.y+=s*(q-m4.y);
}
void ofApp::seteyes(int m, int n){
    eye.x+=s*(m-eye.x);
    eye.y+=s*(n-eye.y);
}
void ofApp::eyes(){
    ofFill();
    ofDrawEllipse(eye.x, eye.y, 8, 11);
    ofDrawEllipse(eye.x*-1, eye.y, 8, 11);
    ofNoFill();
}
void ofApp::scaleFace(int &face){
    
    fradius=face;
}
void ofApp::playSound(int sds){
    if (sd==sds) {
        sound.play();
        if (sds==3) {
            sd=0;
        }else{
            sd++;
        }
    }
    
}
