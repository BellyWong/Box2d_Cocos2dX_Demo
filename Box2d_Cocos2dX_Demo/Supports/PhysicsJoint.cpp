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

b2DistanceJoint* PhysicsJoint::createDistanceJoint(b2Body *body1,
                                                     b2Body *body2,
                                                     b2Vec2 worldAnchorOnBody1,
                                                     b2Vec2 worldAnchorOnBody2){
    b2World *world=BasicPhysics::sharedPhysics()->getWorld();
    b2DistanceJointDef jointDef;
    jointDef.Initialize(body1, body2, worldAnchorOnBody1, worldAnchorOnBody2);
    jointDef.collideConnected=true;
    jointDef.dampingRatio=1.0f;//阻尼率
    jointDef.frequencyHz=0.0f;//震动快慢
    b2DistanceJoint *distanceJoint=(b2DistanceJoint*)world->CreateJoint(&jointDef);
    return distanceJoint;
}

b2RevoluteJoint* PhysicsJoint::createRevoluteJoint(b2Body *body1,
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
    b2RevoluteJoint *joint=(b2RevoluteJoint*)world->CreateJoint(&revoluteJoint);
    return joint;
}

b2MouseJoint* PhysicsJoint::createMouseJoint(CCPoint touchPoint){
    b2World *world=BasicPhysics::sharedPhysics()->getWorld();
    b2Vec2 p=b2Vec2(touchPoint.x/BasicPhysics::sharedPhysics()->getRATIO(),
                                    touchPoint.y/BasicPhysics::sharedPhysics()->getRATIO());
    //查找点中的刚体
    //根据点击位置产生一个小范围
    b2AABB aabb;
    b2Vec2 d;
    d.Set(0.001f, 0.001f);
    aabb.lowerBound=p-d;
    aabb.upperBound=p+d;
    
    b2Body *tBody=NULL;
    b2MouseJoint *mouseJoint;
    
    QueryCallBack *queryCallBack=new QueryCallBack(p);
    world->QueryAABB(queryCallBack, aabb);
    tBody=queryCallBack->getBody();
    
    if (tBody!=NULL) {
        b2MouseJointDef mouseDef;
        mouseDef.bodyA=BasicPhysics::sharedPhysics()->getGroundBody();
        mouseDef.bodyB=tBody;
        mouseDef.target.Set(p.x, p.y);
        mouseDef.maxForce=1000.0f;
        mouseJoint=(b2MouseJoint*)world->CreateJoint(&mouseDef);
    }else{
        mouseJoint=NULL;
    }
    
    return mouseJoint;
}

void PhysicsJoint::updateMouseJoint(b2MouseJoint *mouseJoint,CCPoint touchPoint){
    if (mouseJoint) {
        mouseJoint->SetTarget(b2Vec2(touchPoint.x/BasicPhysics::sharedPhysics()->getRATIO(),
                                     touchPoint.y/BasicPhysics::sharedPhysics()->getRATIO()));
    }
}

void PhysicsJoint::destoryJoint(b2Joint *joint){
    if (joint) {
        b2World *world=BasicPhysics::sharedPhysics()->getWorld();
        world->DestroyJoint(joint);
    }
}