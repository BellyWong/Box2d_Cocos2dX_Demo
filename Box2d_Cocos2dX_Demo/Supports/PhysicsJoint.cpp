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

void PhysicsJoint::createDistanceJoint(b2Body *body1, b2Body *body2,
                                       b2Vec2 worldAnchorOnBody1, b2Vec2 worldAnchorOnBody2){
    b2World *world=BasicPhysics::sharedPhysics()->getWorld();
    b2DistanceJointDef jointDef;
    jointDef.Initialize(body1, body2, worldAnchorOnBody1, worldAnchorOnBody2);
    jointDef.collideConnected=true;
    world->CreateJoint(&jointDef);
}

void PhysicsJoint::createRevoluteJoint(b2Body *body1, b2Body *body2, b2Vec2 worldAnchorOnBody1){
    b2World *world=BasicPhysics::sharedPhysics()->getWorld();
    b2RevoluteJointDef revoluteJoint;
    revoluteJoint.Initialize(body1,body2,worldAnchorOnBody1);
    world->CreateJoint(&revoluteJoint);
}