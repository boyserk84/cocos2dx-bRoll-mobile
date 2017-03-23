//
//  HudDialog.cpp
//  bRoll
//
//  Created by Nate K on 3/22/17.
//
//

#include "HudDialog.hpp"

HudDialog::HudDialog()
{
    dialogId = "HudDialog";
}

void HudDialog::InitDialog()
{
    
    txtfield_Health = Label::createWithSystemFont("Health", "Arial", 30);
    txtfield_Health->setColor(Color3B(255, 255, 255));
    txtfield_Health->setPosition( Vec2(100,100));
    
    
    this->addChild(txtfield_Health);
    
    cocos2d::log("HudDialog.hpp Init()");
}

void HudDialog::Update()
{
    
}


void HudDialog::Destroy()
{
    
}
