#include "MenuScene.h"
#include "TestScene.h"
#include <string>
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
    // auto label = LabelTTF::create("My Hero", "fonts/Marker Felt.ttf", 128);
    // label->setPosition(Vec2(origin.x + visibleSize.width/2,
    //    origin.y + visibleSize.height - label->getContentSize().height));
    // this->addChild(label, 1);
    
    auto label = LabelBMFont::create("My Hero", "fonts/title.fnt");
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);

    // menus
    Vector<MenuItem*> MenuItems;
    int index = 0;
    int step = 100;
    std::string fileMenu = "fonts/Menu_normal.fnt";

    auto label1 = LabelBMFont::create("START", fileMenu);
    auto item1 = MenuItemLabel::create(label1);
    item1->setCallback([&](Ref* sender) {
        Director::getInstance()->replaceScene(TransitionTurnOffTiles::create(0.5f, TestScene::createScene()));
    });
    item1->setPosition(Vec2(origin.x + visibleSize.width/2,
        origin.y + visibleSize.height - label1->getContentSize().height - label->getContentSize().height - (++index)*step));
    MenuItems.pushBack(item1);

    auto label2 = LabelBMFont::create("OPTIONS", fileMenu);
    auto item2 = MenuItemLabel::create(label2);
    item2->setPosition(Vec2(origin.x + visibleSize.width/2,
        origin.y + visibleSize.height - label2->getContentSize().height - label->getContentSize().height - (++index)*step));
    MenuItems.pushBack(item2);

    auto label3 = LabelBMFont::create("EXIT", fileMenu);
    auto item3 = MenuItemLabel::create(label3, CC_CALLBACK_1(MenuScene::menuCloseCallback, this));
    item3->setPosition(Vec2(origin.x + visibleSize.width/2,
        origin.y + visibleSize.height- label3->getContentSize().height - label->getContentSize().height - (++index)*step));
    MenuItems.pushBack(item3);
    
    auto menus = Menu::createWithArray(MenuItems);
    menus->setPosition(Vec2::ZERO);
    this->addChild(menus, 1);

    return true;
}

void MenuScene::menuCloseCallback(Ref *sender) {
    Director::getInstance()->end();
    exit(0);
}

