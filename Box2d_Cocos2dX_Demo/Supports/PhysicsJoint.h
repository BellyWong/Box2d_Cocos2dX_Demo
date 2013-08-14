//
//  PhysicsJoint.h
//  Box2d_Cocos2dX_Demo
//
//  Created by 何遵祖 on 13-7-27.
//
//

#ifndef __Box2d_Cocos2dX_Demo__PhysicsJoint__
#define __Box2d_Cocos2dX_Demo__PhysicsJoint__

#include "cocos2d.h"
#include "BasicPhysics.h"

class PhysicsJoint : public CCObject{
public:
    static PhysicsJoint* sharedJoint();
    //产生距离关节
    b2DistanceJointDef createDistanceJoint(b2Body *body1,
                                           b2Body *body2,
                                           b2Vec2 worldAnchorOnBody1,
                                           b2Vec2 worldAnchorOnBody2);
    //产生旋转关节
    b2RevoluteJointDef createRevoluteJoint(b2Body *body1,
                                           b2Body *body2,
                                           b2Vec2 worldAnchorOnBody1,
                                           bool enableMotor,
                                           float motorSpeed,
                                           float maxMotorTorque);
};

#endif /* defined(__Box2d_Cocos2dX_Demo__PhysicsJoint__) */
