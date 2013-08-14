//
//  RevoluteJoint.h
//  Box2d_Cocos2dX_Demo
//
//  Created by 何遵祖 on 13-7-28.
//
//

#ifndef __Box2d_Cocos2dX_Demo__RevoluteJoint__
#define __Box2d_Cocos2dX_Demo__RevoluteJoint__

#include "cocos2d.h"
#include "BasicPhysics.h"
#include "PhysicsJoint.h"
#include "AbstractScene.h"
#include "Interface.h"

using namespace cocos2d;
class RevoluteJoint : public Interface{
public:
    static CCScene* scene();
    
    virtual bool init();
    
    void createJoint();
    
    virtual void nextScene();
    
    virtual void preScene();
    
    virtual void refresh();
    
    void draw();
    
    virtual void ccTouchesEnded(CCSet *pTouches,CCEvent *pevent);
    
    CREATE_FUNC(RevoluteJoint);
private:
    AbstractScene *a_scene;
};

#endif /* defined(__Box2d_Cocos2dX_Demo__RevoluteJoint__) */
