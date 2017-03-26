//
//  AbstractBaseDialog.hpp
//  bRoll
//
//  Created by Nate K on 3/22/17.
//
//

#ifndef AbstractBaseDialog_hpp
#define AbstractBaseDialog_hpp

#include <stdio.h>
class AbstractBaseDialog :public cocos2d::Node
{
public:
    std::string dialogId = "";
    virtual void InitDialog() = 0;
    virtual void Update() = 0;
    virtual void Destroy() = 0;
    virtual AbstractBaseDialog* Clone() = 0;
};
#endif /* AbstractBaseDialog_hpp */
