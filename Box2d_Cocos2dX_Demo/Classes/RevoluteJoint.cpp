//
//  RevoluteJoint.cpp
//  Box2d_Cocos2dX_Demo
//
//  Created by 何遵祖 on 13-7-28.
//
//

#include "RevoluteJoint.h"
#include "DistanceJoint.h"

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
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    
    //文字提示
    CCLabelTTF *label=CCLabelTTF::create("RevoluteJoint", "Marker Felt", 25);
    label->setPosition(ccp(winSize.width/2,winSize.height-100));
    this->addChild(label);
    
    //抽象层产生
    a_scene=new AbstractScene();
    a_scene->init(this);
    
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
    PhysicsJoint::sharedJoint()->createRevoluteJoint(body1,
                                                     body2,
                                                     body1->GetPosition(),
                                                     true,
                                                     b2_pi*2,
                                                     500);
}

void RevoluteJoint::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pevent){
    CCSetIterator it=pTouches->begin();
    CCTouch *touch=(CCTouch*)(*it);
    CCPoint touchLocation=touch->getLocationInView();
    touchLocation=CCDirector::sharedDirector()->convertToGL(touchLocation);
    
    //添加圆形刚体
    BasicPhysics::sharedPhysics()->createBodyInCircle(NULL,
                                                      touchLocation,
                                                      b2_dynamicBody,
                                                      1.0f, 1.0f, 1.0f,
                                                      0.5f);
}

void RevoluteJoint::nextScene(){
    REPLACE_SCENE(RevoluteJoint);
}

void RevoluteJoint::preScene(){
    REPLACE_SCENE(DistanceJoint);
}

void RevoluteJoint::refresh(){
    REPLACE_SCENE(RevoluteJoint);
}

void RevoluteJoint::draw(){
    a_scene->draw();
}