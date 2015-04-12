//#include <stdio.h>
#include "TestScene.h"

USING_NS_CC;

Scene* TestScene::createScene() {
    Director::getInstance()->setContentScaleFactor(800.f/320.f);
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
    
    auto map = TMXTiledMap::create("bg.tmx");
    auto bgLayer = map->getLayer("bg");
    bgLayer->setAnchorPoint(Vec2(0.5f, 0.5f));
    bgLayer->setPosition(Vec2(origin.x + visableSize.width/2, origin.y + visableSize.height/2));
    this->addChild(map, -1);
    
    auto player = Sprite::create("Player.png");
    player->setPosition(Vec2(visableSize.width/2, visableSize.height/2));
    this->addChild(player);
    auto moveBy = MoveBy::create(2., Vec2(100, 0));
    player->runAction(moveBy);
    
    
    return true;
}
