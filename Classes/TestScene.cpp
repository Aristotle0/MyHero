//#include <stdio.h>
#include "TestScene.h"

USING_NS_CC;

Scene* TestScene::createScene() {
    Scene* scene = Scene::create();
    TestScene* layer = TestScene::create();
    scene->addChild(layer);
    return scene;
}


bool TestScene::init() {
    if (!Layer::init()) {
        return false;
    }
    
    Size visableSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto label = LabelBMFont::create("Hello World!", "fonts/title.fnt");
    label->setPosition(Vec2(origin.x + visableSize.width/2,
                            origin.y + visableSize.height/2));
    this->addChild(label);
    return true;
}
