//
//  DistanceJoint.h
//  Box2d_Cocos2dX_Demo
//
//  Created by 何遵祖 on 13-7-27.
//
//

#ifndef __Box2d_Cocos2dX_Demo__DistanceJoint__
#define __Box2d_Cocos2dX_Demo__DistanceJoint__

#include "Interface.h"
#include "AbstractScene.h"
#include "PhysicsSprite.h"
#include "PhysicsJoint.h"

class DistanceJoint : public Interface{
public:
    DistanceJoint(){};
    ~DistanceJoint(){CC_SAFE_DELETE(a_scene);};
    
    static CCScene* scene();
    
    virtual bool init();
    
    virtual void ccTouchesEnded(CCSet *pTouches,CCEvent *pevent);

    virtual void nextScene();
    
    virtual void preScene();
    
    virtual void refresh();
    
    void update(float dt);
    
    void draw();
    
    CREATE_FUNC(DistanceJoint);
private:
    b2Body *body1;
    b2Body *body2;
    
    AbstractScene *a_scene;
};

#endif /* defined(__Box2d_Cocos2dX_Demo__DistanceJoint__) */
