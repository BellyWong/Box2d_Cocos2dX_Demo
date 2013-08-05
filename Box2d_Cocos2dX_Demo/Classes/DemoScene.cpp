//
//  DemoScene.cpp
//  Box2d_Cocos2dX_Demo
//
//  Created by 何遵祖 on 13-7-27.
//
//

#include "DemoScene.h"
#include "SimpleAudioEngine.h"
#include "script_support/CCScriptSupport.h"
#include "CCLuaEngine.h"

using namespace CocosDenshion;
CCScene* DemoScene::scene(){
    CCScene *scene=CCScene::create();
    DemoScene *layer=DemoScene::create();
    scene->addChild(layer);
    return scene;
}

bool DemoScene::init(){
    if (!CCLayer::init()) {
        return false;
    }
   
    
    //初始化
    a_scene=new AbstractScene();
    a_scene->init(this);
    
    //添加box刚体
    BasicPhysics::sharedPhysics()->createBody(NULL,
                                              ccp(100,100),
                                              b2_dynamicBody,
                                              1.0f, 1.0f, 1.0f,
                                              CCSizeMake(30.0f, 30.0f));
    //是否可以响应触碰事件
    this->setTouchEnabled(true);
    scheduleUpdate();
    return true;
}

void DemoScene::ccTouchesEnded(CCSet *pTouches,CCEvent *pevent){
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

void DemoScene::nextScene(){
    REPLACE_SCENE(DistanceJoint);
}

void DemoScene::preScene(){
    CCLOG("这是第一个场景");
}

void DemoScene::refresh(){
    REPLACE_SCENE(DemoScene);
}

void DemoScene::update(float dt){
    a_scene->update(dt);
}

void DemoScene::draw(){
    a_scene->draw();
}