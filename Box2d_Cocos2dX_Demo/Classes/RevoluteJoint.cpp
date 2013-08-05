//
//  RevoluteJoint.cpp
//  Box2d_Cocos2dX_Demo
//
//  Created by 何遵祖 on 13-7-28.
//
//

#include "RevoluteJoint.h"

CCScene* RevoluteJoint::scene(){
    CCScene* scene=CCScene::create();
    RevoluteJoint *layer=RevoluteJoint::create();
    scene->addChild(layer);
    return scene;
}

bool RevoluteJoint::init(){
    if (!CCLayer::init()) {
        return false;
    }
    
    //产生关节
    this->createJoint();
    
    scheduleUpdate();
    this->setTouchEnabled(true);
    return true;
}

void RevoluteJoint::createJoint(){
    b2Body *body1=BasicPhysics::sharedPhysics()->createBodyInCircle(NULL,
                                                                    ccp(240,140),
                                                                    b2_staticBody,
                                                                    1.0f, 1.0f, 1.0f,
                                                                    0.5f);
    b2Body *body2=BasicPhysics::sharedPhysics()->createBodyInCircle(NULL,
                                                                    ccp(320, 140),
                                                                    b2_dynamicBody,
                                                                    1.0f, 1.0f, 1.0f,
                                                                    0.5f);
    PhysicsJoint::sharedJoint()->createRevoluteJoint(body1, body2, body1->GetPosition());
}

void RevoluteJoint::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pevent){
    
}

void RevoluteJoint::update(float dt){
    BasicPhysics::sharedPhysics()->update(dt);
}

void RevoluteJoint::draw(){
    BasicPhysics::sharedPhysics()->draw();
}