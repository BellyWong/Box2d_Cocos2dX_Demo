//
//  DistanceJoint.cpp
//  Box2d_Cocos2dX_Demo
//
//  Created by 何遵祖 on 13-7-27.
//
//

#include "DistanceJoint.h"
#include "DemoScene.h"

CCScene* DistanceJoint::scene(){
    CCScene *scene=CCScene::create();
    DistanceJoint *layer=DistanceJoint::create();
    scene->addChild(layer);
    return scene;
}

bool DistanceJoint::init(){
    if (!CCLayer::init()) {
        return false;
    }
    
    a_scene=new AbstractScene();
    a_scene->init(this);
    
    body1=BasicPhysics::sharedPhysics()->createBody(NULL,
                                                    ccp(150,300),
                                                    b2_staticBody,
                                                    1.0f, 1.0f, 1.0f,
                                                    CCSizeMake(120, 30));
    body2=BasicPhysics::sharedPhysics()->createBodyInCircle(NULL,
                                                            ccp(50,150),
                                                            b2_dynamicBody,
                                                            1.0f, 1.0f, 1.0f,
                                                            1.0f);
    
    PhysicsJoint::sharedJoint()->createDistanceJoint(body1, body2,
                                                     body1->GetPosition(), body2->GetPosition());
    
    this->scheduleUpdate();
    this->setTouchEnabled(true);
    return true;
}

void DistanceJoint::ccTouchesEnded(CCSet* pTouches, CCEvent *pEvent){
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

void DistanceJoint::nextScene(){
    CCLOG("这是最后一个场景");
}

void DistanceJoint::preScene(){
    REPLACE_SCENE(DemoScene);
}

void DistanceJoint::refresh(){
    REPLACE_SCENE(DistanceJoint);
}

void DistanceJoint::update(float dt){
    a_scene->update(dt);
}

void DistanceJoint::draw(){
    a_scene->draw();
}