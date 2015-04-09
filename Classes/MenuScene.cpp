#include "MenuScene.h"

USING_NS_CC;

Scene* MenuScene::createScene() {
    auto scene = Scene::create();
    auto layer = MenuScene::create();
    scene->addChild(layer);
    return scene;
}

bool MenuScene::init() {
    if (!Layer::init()) {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // background figure
    auto bgFigure = Sprite::create("main.png");
    bgFigure->setPosition(Vec2(origin.x + visibleSize.width/2, 
        origin.y + visibleSize.height/2));
    this->addChild(bgFigure, 0);

    // label
    auto label = LabelTTF::create("My Hero", "fonts/Marker Felt.ttf", 128);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
        origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);

    // menus
    Vector<MenuItem*> MenuItems;
    int index = 2;

    auto label1 = LabelTTF::create("START", "Marker Felt.ttf", 56);
    auto item1 = MenuItemLabel::create(label1);
    label1->setPosition(Vec2(origin.x + visibleSize.width/2,
        origin.y + visibleSize.height - label1->getContentSize().height - (++index)*80));
    MenuItems.pushBack(item1);

    auto label2 = LabelTTF::create("OPTIONS", "Marker Felt.ttf", 56);
    auto item2 = MenuItemLabel::create(label2);
    label2->setPosition(Vec2(origin.x + visibleSize.width/2,
        origin.y + visibleSize.height - label2->getContentSize().height - (++index)*80));
    MenuItems.pushBack(item2);

    auto label3 = LabelTTF::create("EXIT", "Marker Felt.ttf", 56);
    auto item3 = MenuItemLabel::create(label3);
    label3->setPosition(Vec2(origin.x + visibleSize.width/2,
        origin.y + visibleSize.height- label3->getContentSize().height - (++index)*80));
    MenuItems.pushBack(item3);

    auto menus = Menu::createWithArray(MenuItems);
    menus->setPosition(Vec2::ZERO);
    this->addChild(menus, 1);

    return true;
}

