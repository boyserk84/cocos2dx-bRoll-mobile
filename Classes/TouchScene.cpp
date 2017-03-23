//
//  TouchScene.cpp
//  bRoll
//
//  Created by Nate K on 3/20/17.
//
//

#include "TouchScene.hpp"
#include "TouchSprite.hpp"
#include "HudDialog.hpp"    // remove this once done

USING_NS_CC;

Scene* TouchScene::createScene()
{
    auto scene = Scene::create();
    auto layer = TouchScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool TouchScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    initTouch();
    
    // Add character
    auto mainCharacter = TouchSprite::create("Idle (1).png", true);
    mainCharacter->setPosition(Vec2(
                                Director::getInstance()->getVisibleSize().width / 2,
                                   Director::getInstance()->getVisibleSize().height / 2));
    this->addChild(mainCharacter, 1);
    cocos2d::log("TouchScene Init Main is done!");
    
    HudDialog* hudDialog = new HudDialog();
    hudDialog->InitDialog();
    this->addChild(hudDialog);
    cocos2d::log("Hud Init Main is done!");
    
    return true;
}

bool TouchScene::initTouch()
{
    labelTouchInfo = Label::createWithSystemFont("Touch or clicksomewhere to begin", "Arial", 30);
    
    labelTouchInfo->setPosition(Vec2(
                                     Director::getInstance()->getVisibleSize().width / 2,
                                     Director::getInstance()->getVisibleSize().height / 2));
    
    // Create a touch event listener
    auto touchListener = EventListenerTouchOneByOne::create();
    
    // Subscriber methods
    touchListener->onTouchBegan = CC_CALLBACK_2(TouchScene::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(TouchScene::onTouchEnded, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(TouchScene::onTouchMoved, this);
    touchListener->onTouchCancelled = CC_CALLBACK_2(TouchScene::onTouchCancelled, this);
    
    // Add this event listener to this TouchScene
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    // Add this labelTouchInfo to Node Scene
    this->addChild(labelTouchInfo,0);
    cocos2d::log("initTouch() is done!");
    return true;
}

/**
 *
 */
bool TouchScene::onTouchBegan(Touch* touch, Event* event)
{
    labelTouchInfo->setPosition(touch->getLocation());
    labelTouchInfo->setString("You Touched Here");
    return true;
}

void TouchScene::onTouchEnded(Touch* touch, Event* event)
{
    cocos2d::log("touch ended ");
    
}

void TouchScene::onTouchMoved(Touch* touch, Event* event)
{
    cocos2d::log("touch moved");
}

void TouchScene::onTouchCancelled(Touch* touch, Event* event)
{
    cocos2d::log("touch cancelled");
}
