#ifndef MYHERO_TESTSCENE_H_
#define MYHERO_TESTSCENE_H_

#include "cocos2d.h"

class TestScene : public cocos2d::Layer {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(TestScene);
};


#endif
