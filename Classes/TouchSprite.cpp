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
    // Initialize SpriteFrame
    if ( this->initWithSpriteFrameName(_srcPath))
    {
       // this->setScale( 2 );
        
        return true;
    }
    
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
 
    //auto _listener = EventListenerCustom::create("touchBegin", std::bind(&TouchSprite::OnGameMove, this, std::placeholders::_1));
    
    //getEventDispatcher()->addEventListenerWithSceneGraphPriority(_listener, this);
}

// TODO: Implement GameEventListener
void TouchSprite::OnGameEventReceived(std::string eventName, EventCustom* event)
{
    //cocos2d::Vec2* loc = (cocos2d::Vec2*) event->getUserData();
    //this->setPosition( *loc );
    //cocos2d::log(sprintf("OngameEventReceived %s",eventName.c_str()));
    
    if ( this->getNumberOfRunningActions() == 0 )
    {
        cocos2d::Vec2* loc = (cocos2d::Vec2*) event->getUserData();
        cocos2d::Vec2 curLoc = this->getPosition();
        auto moveTo = MoveTo::create(2, Vec2(curLoc.x - 55, curLoc.y));
        if ( curLoc.x < loc->x)
        {
            moveTo = MoveTo::create(2, Vec2(curLoc.x + 55, curLoc.y));
        }
        
        // Get Animation Key
        auto animation = AnimationCache::getInstance()->getAnimation("animation_1");
        auto animate = Animate::create( animation );    // Create an animate action
        //this->runAction( animate );//RepeatForever::create( animate ) );
        
        //auto seq = Sequence::create(animate, nullptr);
        this->runAction(animate);
        this->runAction(moveTo);
        cocos2d::log("Moving Seq");
    }
   // this->setPosition( *loc );
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
