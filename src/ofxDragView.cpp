//
//  ofxDragView.cpp
//
//
//  Created by erik on 7/21/14.
//
//

#include "ofxDragView.h"


ofxDragView::ofxDragView(int x, int y, int w, int h)
{
    setup(x, y, w, h);
}

void ofxDragView::setup(int x, int y, int w, int h)
{
    disableAllEvents();
//    enableAppEvents();
    enableMouseEvents();
    set(x, y, w, h);
}




void ofxDragView::onPress(int x, int y, int button)
{
    // save the offset of where the mouse was clicked...
    // ...relative to the position of the object
    saveX = this->x - x;
    saveY = this->y - y;
    onPressed = true;
}

void ofxDragView::onPressOutside(int x, int y, int button){
    onPressed = false;
}

void ofxDragView::onRelease(int x, int y, int button){
    onPressed = false;
}
void ofxDragView::onReleaseOutside(int x, int y, int button){
    onPressed = false;
}


void ofxDragView::mouseDragged(int x, int y, int button)
{
    if(onPressed)
    {
        this->x = x + saveX;
        this->y = y + saveY;
    }
}


void ofxDragView::begin()
{
    ofPushMatrix();
    ofTranslate(getPositionRef());
}

void ofxDragView::end()
{
    ofPopMatrix();
}