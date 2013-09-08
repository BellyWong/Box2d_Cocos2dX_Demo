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

class QueryCallBack : public b2QueryCallback{
public:
    QueryCallBack(b2Vec2 point){
        p=point;
        m_body=NULL;
    };
    bool ReportFixture(b2Fixture *fixture){
        b2Shape *shape=fixture->GetShape();
        if (fixture->GetBody()->GetType()!=b2_staticBody) {
            bool inside=shape->TestPoint(fixture->GetBody()->GetTransform(),p);
            if (inside) {
                m_body=fixture->GetBody();
                return false;
            }
        }
        return true;
    };
private:
    CC_SYNTHESIZE_READONLY(b2Body*, m_body, Body);
    CC_SYNTHESIZE_READONLY(b2Vec2, p, Vector);
};

class PhysicsJoint : public CCObject{
public:
    static PhysicsJoint* sharedJoint();
    //产生距离关节
    b2DistanceJoint* createDistanceJoint(b2Body *body1,
                                           b2Body *body2,
                                           b2Vec2 worldAnchorOnBody1,
                                           b2Vec2 worldAnchorOnBody2);
    //产生旋转关节
    b2RevoluteJoint* createRevoluteJoint(b2Body *body1,
                                           b2Body *body2,
                                           b2Vec2 worldAnchorOnBody1,
                                           bool enableMotor,
                                           float motorSpeed,
                                           float maxMotorTorque);
    //以下都是鼠标关节
    //产生鼠标关节(使用在触摸开始ccTouchBegan/ccTouchEnded调用destory删除关节)
    b2MouseJoint* createMouseJoint(CCPoint touchPoint);
    //更新旋转关节(使用在触摸移动ccTouchMoved)
    void updateMouseJoint(b2MouseJoint *mouseJoint,CCPoint touchPoint);
    
    //删除关节
    void destoryJoint(b2Joint *joint);
};

#endif /* defined(__Box2d_Cocos2dX_Demo__PhysicsJoint__) */
