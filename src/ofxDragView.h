//
//  ofxDragView.h
//
//
//  Created by erik on 7/21/14.
//
//

#pragma once

#include "ofxMSAInteractiveObject.h"

class ofxDragView : public ofxMSAInteractiveObject
{
protected:
    bool onPressed;
    int saveX, saveY;
    
public:
    ofxDragView();
    virtual void update();
    virtual void onPress(int x, int y, int button);
    virtual void onRelease(int x, int y, int button);    
    void begin();
    void end();
};


