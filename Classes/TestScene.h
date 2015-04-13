#ifndef MYHERO_TESTSCENE_H_
#define MYHERO_TESTSCENE_H_

USING_NS_CC;

class TestScene : public Layer {
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(TestScene);
    Point convertPointToTiledPoint(Point touchpoint, TMXTiledMap *map);
};


#endif
