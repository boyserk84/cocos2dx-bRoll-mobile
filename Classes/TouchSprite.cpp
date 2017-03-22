//
//  TouchSprite.cpp
//  bRoll
//
//  Created by Nate K on 3/21/17.
//
//

#include "TouchSprite.hpp"

using namespace cocos2d;


TouchSprite* TouchSprite::create(std::string path, bool consumeByTouch)
{
    TouchSprite* sprite = new TouchSprite(path);
    if ( sprite->init() )
    {
        sprite->shouldConsumeByTouch = consumeByTouch;
        sprite->addEvents();
        cocos2d::log("Create TouchSprite!");
        return sprite;
    }
    
    CC_SAFE_DELETE(sprite);
    return NULL;
}


/** Default constructor */
TouchSprite::TouchSprite(){}

/** Deconstructor */
TouchSprite::~TouchSprite(){}

TouchSprite::TouchSprite(std::string path)
{
    _srcPath = path;
}

/** Initialize */
bool TouchSprite::init()
{
    cocos2d::log("TouchSprite::Init is done!");
    if ( Sprite::initWithFile(_srcPath) )
        return true;
    
    return false;
}


/** add touch events */
void TouchSprite::addEvents()
{
    
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(TouchSprite::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(TouchSprite::onTouchEnded, this);
    listener->onTouchMoved = CC_CALLBACK_2(TouchSprite::onTouchMoved, this);
    listener->onTouchCancelled = CC_CALLBACK_2(TouchSprite::onTouchCancelled, this);
    
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener->clone(), this);
}


bool TouchSprite::onTouchBegan(cocos2d::Touch* t, cocos2d::Event* e)
{
    // TODO: Code
    //this->setPosition( t->getLocation() );
    cocos2d::log("touch Began ");
    
    cocos2d::Rect rect = this->getBoundingBox();
    if ( shouldConsumeByTouch && rect.containsPoint(t->getLocation()) )
    {
        cocos2d::log(" Consume by touch");
        // Test this out
        this->setPosition( t->getLocation() );
        return true;
    }
    
    return false;
}

void TouchSprite::onTouchEnded(cocos2d::Touch* t, cocos2d::Event* e)
{
    // TODO: Implementation needed
}
void TouchSprite::onTouchMoved(cocos2d::Touch* t, cocos2d::Event* e)
{
    // TODO: Implementation needed
}
void TouchSprite::onTouchCancelled(cocos2d::Touch* t, cocos2d::Event* e)
{
    // TODO: Implementation needed
}

