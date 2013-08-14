//
//  DemoScene.h
//  Box2d_Cocos2dX_Demo
//
//  Created by 何遵祖 on 13-7-27.
//
//

#ifndef __Box2d_Cocos2dX_Demo__DemoScene__
#define __Box2d_Cocos2dX_Demo__DemoScene__

#include "Interface.h"
#include "PhysicsSprite.h"
#include "AbstractScene.h"
#include "DistanceJoint.h"

using namespace cocos2d;

class DemoScene : public Interface {
public:
    DemoScene(){};
    ~DemoScene(){
        CC_SAFE_DELETE(a_scene);
    };
    
    static CCScene* scene();
    
    virtual bool init();
    
    virtual void ccTouchesEnded(CCSet *pTouches,CCEvent *pevent);
    
    void draw();
    
    virtual void nextScene();
    
    virtual void preScene();
    
    virtual void refresh();
    
    CREATE_FUNC(DemoScene);
private:
    AbstractScene *a_scene;
};

#endif /* defined(__Box2d_Cocos2dX_Demo__DemoScene__) */
