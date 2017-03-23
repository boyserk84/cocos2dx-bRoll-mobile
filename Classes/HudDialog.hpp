//
//  HudDialog.hpp
//  bRoll
//
//  Created by Nate K on 3/22/17.
//
//

#ifndef HudDialog_hpp
#define HudDialog_hpp

#include <stdio.h>
#include "AbstractBaseDialog.hpp"

using namespace cocos2d;

class HudDialog : public virtual AbstractBaseDialog  {
    
public:
    Sprite* title;
    Label* txtfield_Health;
    
    HudDialog();
    ~HudDialog();
    
    void InitDialog();
    void Update();
    void Destroy();
    
};

#endif /* HudDialog_hpp */
