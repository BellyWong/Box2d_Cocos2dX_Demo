//
//  Interface.h
//  Box2d_Cocos2dX_Demo
//
//  Created by 何遵祖 on 13-8-5.
//
//

#ifndef __Box2d_Cocos2dX_Demo__Interface__
#define __Box2d_Cocos2dX_Demo__Interface__

#include "cocos2d.h"

using namespace cocos2d;

class Interface : public CCLayer{
public:
    virtual void nextScene()=0;
    virtual void preScene()=0;
    virtual void refresh()=0;
};
#endif /* defined(__Box2d_Cocos2dX_Demo__Interface__) */
