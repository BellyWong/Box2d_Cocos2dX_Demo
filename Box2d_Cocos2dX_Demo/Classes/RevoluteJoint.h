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

using namespace cocos2d;
class RevoluteJoint : public CCLayer{
public:
    static CCScene* scene();
    
    virtual bool init();
    
    void createJoint();
    
    void update(float dt);
    void draw();
    
    virtual void ccTouchesEnded(CCSet *pTouches,CCEvent *pevent);
    
    CREATE_FUNC(RevoluteJoint);
};

#endif /* defined(__Box2d_Cocos2dX_Demo__RevoluteJoint__) */
