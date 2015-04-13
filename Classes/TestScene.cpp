//#include <stdio.h>
#include "TestScene.h"
#include <iostream>

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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size winSize = Director::getInstance()->getWinSize();
    
    CCLOG("winSize: (%f, %f)", winSize.width, winSize.height);
    CCLOG("visibleSize: (%f, %f)", visibleSize.width, visibleSize.height);
    CCLOG("origin: (%f, %f)", origin.x, origin.y);
    
    auto map = TMXTiledMap::create("bg.tmx");
    auto bgLayer = map->getLayer("bg");
    bgLayer->setAnchorPoint(Vec2(0.5f, 0.5f));
    bgLayer->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    bgLayer->setTileGID(32, convertPointToTiledPoint(Vec2(visibleSize.width/2, visibleSize.height/2), map));
//    bgLayer->setTileGID(32, convertPointToTiledPoint(Vec2(33., 33.), map));
    this->addChild(map, -1);
    CCLOG("layer: %f", this->getPositionX());
    CCLOG("bgLayer: %f", bgLayer->getPositionX());
    CCLOG("map: (%f, %f)", map->getPositionX(), map->getPositionY());
    
    auto objectsGroup = map->getObjectGroup("objects");
    auto startPos = objectsGroup->getObject("startPos");
    float pointX = startPos["x"].asFloat();
    float pointY = startPos["y"].asFloat();
    CCLOG("object: (%f, %f)", pointX, pointY);

    
    auto player = Sprite::create("Player.png");
    player->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    this->addChild(player);
//    auto moveBy = MoveBy::create(2., Vec2(100, 0));
//    player->runAction(moveBy);
    
    
    return true;
}

Point TestScene::convertPointToTiledPoint(Point touchpoint, TMXTiledMap *map) {
    CCLOG("touchpoint: (%f, %f)", touchpoint.x, touchpoint.y);
    float factor1 = Director::getInstance()->getContentScaleFactor();
    CCLOG("factor: %f", factor1);
    CCLOG("map_pos: (%f, %f)", map->getPositionX(), map->getPositionY());
    Point point = (touchpoint - map->getPosition())*Director::getInstance()->getContentScaleFactor();
    //point.x += 320 - 240;
    CCLOG("tilepoint_before: (%f, %f)", point.x, point.y);
    point.x = (int) (point.x / map->getTileSize().width);
    point.y = (int) ((map->getMapSize().height * map->getTileSize().height - point.y) /
                     map->getTileSize().height);
    CCLOG("tilepoint: (%f, %f)", point.x, point.y);
    return point;
}


