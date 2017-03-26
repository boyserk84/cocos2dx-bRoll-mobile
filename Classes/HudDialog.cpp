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

HudDialog::~HudDialog()
{
    cocos2d::log("HudDialog has been destroyed!");
}

/** Copy Constructor */
HudDialog::HudDialog(const HudDialog &source)
{
    // TODO: Test this
    this->title = source.title;
    this->txtfield_Health = source.txtfield_Health;
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

AbstractBaseDialog* HudDialog::Clone()
{
    return new HudDialog(*this);
}
