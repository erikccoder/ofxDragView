//
//  ofxDragView.cpp
//
//
//  Created by erik on 7/21/14.
//
//

#include "ofxDragView.h"

ofxDragView::ofxDragView()
{
    enableMouseEvents();
}

void ofxDragView::update()
{
    if (onPressed)
    {
        this->x = ofGetMouseX() - saveX;    // update x position
        this->y = ofGetMouseY() - saveY;    // update mouse y position
    }
}

void ofxDragView::onPress(int x, int y, int button)
{
    // save the offset of where the mouse was clicked...
    // ...relative to the position of the object
    saveX = x - this->x;
    saveY = y - this->y;
    onPressed = true;
}

void ofxDragView::onRelease(int x, int y, int button)
{
    onPressed = false;
}

void ofxDragView::begin()
{
    ofPushMatrix();
    ofTranslate(getPosition());
}

void ofxDragView::end()
{
    ofPopMatrix();
}