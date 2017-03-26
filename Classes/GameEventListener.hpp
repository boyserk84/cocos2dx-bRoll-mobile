//
//  GameEventListener.hpp
//  bRoll
//
//  Created by Nate K on 3/24/17.
//
//

#ifndef GameEventListener_hpp
#define GameEventListener_hpp

#include <stdio.h>
class GameEventListener {
public:
    void virtual HandleEvent(std::string eventName, cocos2d::EventCustom* data);
};
#endif /* GameEventListener_hpp */
