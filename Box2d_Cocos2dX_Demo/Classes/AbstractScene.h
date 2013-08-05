//
//  SceneManager.h
//  Box2d_Cocos2dX_Demo
//
//  Created by 何遵祖 on 13-7-27.
//
//

#ifndef __Box2d_Cocos2dX_Demo__SceneManager__
#define __Box2d_Cocos2dX_Demo__SceneManager__

#include "cocos2d.h"
#include "BasicPhysics.h"
#include "Interface.h"

#define REPLACE_SCENE(__TYPE__) CCDirector::sharedDirector()->replaceScene(__TYPE__::scene());

enum {
    DistanceJoint = 100,
};

enum {
    b_fresh  = -1,
    b_format = 1,
    b_back   = 0,
};

using namespace cocos2d;

class AbstractScene : public CCObject{
public:
   virtual bool init(Interface* currentLayer);
   void update(float dt);
   void draw();
private:
    void Btn_callback(CCObject *object);
    Interface *current;
};

#endif /* defined(__Box2d_Cocos2dX_Demo__SceneManager__) */
