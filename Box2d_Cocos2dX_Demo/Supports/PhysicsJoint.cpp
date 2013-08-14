//
//  PhysicsJoint.cpp
//  Box2d_Cocos2dX_Demo
//
//  Created by 何遵祖 on 13-7-27.
//
//

#include "PhysicsJoint.h"

static PhysicsJoint *_physicsJoint;
PhysicsJoint* PhysicsJoint::sharedJoint(){
    if (!_physicsJoint) {
        _physicsJoint=new PhysicsJoint();
    }
    return _physicsJoint;
}

b2DistanceJointDef PhysicsJoint::createDistanceJoint(b2Body *body1,
                                                     b2Body *body2,
                                                     b2Vec2 worldAnchorOnBody1,
                                                     b2Vec2 worldAnchorOnBody2){
    b2World *world=BasicPhysics::sharedPhysics()->getWorld();
    b2DistanceJointDef jointDef;
    jointDef.Initialize(body1, body2, worldAnchorOnBody1, worldAnchorOnBody2);
    jointDef.collideConnected=true;
    jointDef.dampingRatio=1.0f;//阻尼率
    jointDef.frequencyHz=0.0f;//震动快慢
    world->CreateJoint(&jointDef);
    return jointDef;
}

b2RevoluteJointDef PhysicsJoint::createRevoluteJoint(b2Body *body1,
                                                     b2Body *body2,
                                                     b2Vec2 worldAnchorOnBody1,
                                                     bool enableMotor,
                                                     float motorSpeed,
                                                     float maxMotorTorque)
{
    b2World *world=BasicPhysics::sharedPhysics()->getWorld();
    b2RevoluteJointDef revoluteJoint;
    revoluteJoint.Initialize(body1,body2,worldAnchorOnBody1);
    revoluteJoint.enableMotor=enableMotor;//开启关节马达
    revoluteJoint.motorSpeed=motorSpeed;//马达速度
    revoluteJoint.maxMotorTorque=maxMotorTorque;
    world->CreateJoint(&revoluteJoint);
    return revoluteJoint;
}