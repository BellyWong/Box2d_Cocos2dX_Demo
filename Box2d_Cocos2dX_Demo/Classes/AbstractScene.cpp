//
//  SceneManager.cpp
//  Box2d_Cocos2dX_Demo
//
//  Created by 何遵祖 on 13-7-27.
//
//

#include "AbstractScene.h"
#include "DistanceJoint.h"

bool AbstractScene::init(Interface* currentLayer){
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    
    //前进按钮
    CCSprite *format_btn=CCSprite::create("pullarrow.png");
    CCSprite *format_btn_use=CCSprite::create("pullarrow.png");
    format_btn_use->setOpacity(0);
    CCMenuItemSprite *btn1=CCMenuItemSprite::create(format_btn,format_btn_use, this, menu_selector(AbstractScene::Btn_callback));
    btn1->setTag(b_format);
    
    //后退按钮
    CCSprite *back_btn=CCSprite::create("pullarrow_2.png");
    CCSprite *back_btn_use=CCSprite::create("pullarrow_2.png");
    back_btn_use->setOpacity(0);
    CCMenuItemSprite *btn2=CCMenuItemSprite::create(back_btn,back_btn_use, this, menu_selector(AbstractScene::Btn_callback));
    btn2->setTag(b_back);
    
    //刷新按钮
    CCSprite *fresh_btn=CCSprite::create("refresh.png");
    fresh_btn->setScale(0.8f);
    fresh_btn->setOpacity(100);
    CCSprite *fresh_btn_use=CCSprite::create("refresh.png");
    fresh_btn_use->setOpacity(0);
    fresh_btn_use->setScale(0.8f);
    CCMenuItemSprite *fresh=CCMenuItemSprite::create(fresh_btn,fresh_btn_use, this, menu_selector(AbstractScene::Btn_callback));
    fresh->setTag(b_fresh);
    
    CCMenu *menu=CCMenu::create(btn2,fresh,btn1,NULL);
    menu->setPosition(ccp(size.width/2,30));
    menu->alignItemsHorizontallyWithPadding(10.0f);
    currentLayer->addChild(menu);
    
    current=currentLayer;
    
    return true;
}

void AbstractScene::Btn_callback(CCObject *object){
    BasicPhysics::sharedPhysics()->end();
    CCMenuItemSprite *btnObj=dynamic_cast<CCMenuItemSprite*>(object);
    if (btnObj->getTag()==b_format) {
        current->nextScene();
    }else if(btnObj->getTag()==b_back){
        current->preScene();
    }else if(btnObj->getTag()==b_fresh){
        current->refresh();
    }
}

void AbstractScene::draw(){
    BasicPhysics::sharedPhysics()->draw();
}