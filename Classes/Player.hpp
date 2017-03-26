//
//  Player.hpp
//  bRoll
//
//  Created by Nate K on 3/22/17.
//
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "TouchSprite.hpp"
class Player {
    
    
public:
    Player();
    ~Player();
    
private:
    cocos2d::Vec2* _curPos;
    float _curHealth;
    float _curDetracterPoint;
    
    TouchSprite* _sprite;
};
#endif /* Player_hpp */
