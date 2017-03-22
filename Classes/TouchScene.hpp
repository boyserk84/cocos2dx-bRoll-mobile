//
//  TouchScene.hpp
//  bRoll
//
//  Created by Nate K on 3/20/17.
//
//

#ifndef TouchScene_hpp
#define TouchScene_hpp

#pragma once
#include <stdio.h>
#include "cocos2d.h"

class TouchScene:public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);
    virtual bool initTouch();
    CREATE_FUNC(TouchScene);
  
private:
    cocos2d::Label* labelTouchInfo;
};

#endif /* TouchScene_hpp */
