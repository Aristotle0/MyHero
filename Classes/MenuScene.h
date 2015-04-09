#ifndef MENUSCENE_H_
#define MENUSCENE_H_

#include "cocos2d.h"

class MenuScene : public cocos2d::Layer {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    //void menuCloseCallback(cocos2d:Ref* pSender);
    CREATE_FUNC(MenuScene);

};


#endif