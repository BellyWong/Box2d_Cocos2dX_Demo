//
//  MouseJoint.cpp
//  Box2d_Cocos2dX_Demo
//
//  Created by 何遵祖 on 13-9-7.
//
//

#include "MouseJoint.h"
#include "RevoluteJoint.h"

CCScene* MouseJoint::scene(){
    CCScene *scene=CCScene::create();
    MouseJoint *layer=MouseJoint::create();
    scene->addChild(layer);
    return scene;
}

bool MouseJoint::init(){
    if (!CCLayer::init()) {
        return false;
    }
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    
    //文字提示
    CCLabelTTF *label=CCLabelTTF::create("MouseJoint", "Marker Felt", 25);
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

void MouseJoint::createJoint(){
    for (int i=0; i<5; i++) {
        activeBody=BasicPhysics::sharedPhysics()->createBodyInCircle(NULL,
                                                                     ccp(arc4random()%50+250,
                                                                         arc4random()%100+100),
                                                                     b2_dynamicBody,
                                                                     1.0f, 1.0f, 1.0f,
                                                                     arc4random()%1+0.5f);
    }

}

void MouseJoint::nextScene(){
    REPLACE_SCENE(MouseJoint);
}

void MouseJoint::preScene(){
    REPLACE_SCENE(RevoluteJoint);
}

void MouseJoint::refresh(){
    REPLACE_SCENE(MouseJoint);
}

void MouseJoint::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pevent){
    CCSetIterator it=pTouches->begin();
    CCTouch *touch=(CCTouch*)(*it);
    CCPoint touchLocation=touch->getLocationInView();
    touchLocation=CCDirector::sharedDirector()->convertToGL(touchLocation);
    
    mouseJoint=PhysicsJoint::sharedJoint()->createMouseJoint(touchLocation);
}

void MouseJoint::ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pevent){
    CCSetIterator it=pTouches->begin();
    CCTouch *touch=(CCTouch*)(*it);
    CCPoint touchLocation=touch->getLocationInView();
    touchLocation=CCDirector::sharedDirector()->convertToGL(touchLocation);
    
    PhysicsJoint::sharedJoint()->updateMouseJoint(mouseJoint,touchLocation);
}

void MouseJoint::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pevent){
    PhysicsJoint::sharedJoint()->destoryJoint(mouseJoint);
}

void MouseJoint::draw(){
    a_scene->draw();
}