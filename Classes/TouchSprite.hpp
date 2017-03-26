//
//  TouchSprite.hpp
//  bRoll
//
//  Created by Nate K on 3/21/17.
//
//

#ifndef TouchSprite_hpp
#define TouchSprite_hpp

#include <stdio.h>
#include "GameEventListener.hpp"

class TouchSprite: public cocos2d::Sprite
{
    
public:
    
    bool shouldConsumeByTouch;
    
    TouchSprite();
    TouchSprite(std::string path);
    ~TouchSprite();
    static TouchSprite* create(std::string path, bool consumeByTouch);
    
    bool init();
    void addEvents();
    void OnGameEventReceived(std::string eventName, cocos2d::EventCustom* event);
    
    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);
private:
    
    std::string _srcPath;

};

#endif /* TouchSprite_hpp */
