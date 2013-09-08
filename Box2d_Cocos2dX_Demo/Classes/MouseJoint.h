//
//  MouseJoint.h
//  Box2d_Cocos2dX_Demo
//
//  Created by 何遵祖 on 13-9-7.
//
//

#ifndef __Box2d_Cocos2dX_Demo__MouseJoint__
#define __Box2d_Cocos2dX_Demo__MouseJoint__

#include "cocos2d.h"
#include "AbstractScene.h"
#include "Interface.h"

using namespace cocos2d;

class MouseJoint : public Interface{
public:
    static CCScene* scene();
    
    virtual bool init();
    
    void createJoint();
    
    virtual void nextScene();
    
    virtual void preScene();
    
    virtual void refresh();
    
    virtual void ccTouchesBegan(CCSet *pTouches,CCEvent *pevent);
    virtual void ccTouchesMoved(CCSet *pTouches,CCEvent *pevent);
    virtual void ccTouchesEnded(CCSet *pTouches,CCEvent *pevent);
    
    void draw();
    
    CREATE_FUNC(MouseJoint);
private:
    AbstractScene *a_scene;
    b2Body *activeBody;
    b2MouseJoint *mouseJoint;
};

#endif /* defined(__Box2d_Cocos2dX_Demo__MouseJoint__) */
