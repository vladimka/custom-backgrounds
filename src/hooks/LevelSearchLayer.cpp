#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include "../CustomBackground.hpp"
using namespace geode::prelude;

class $modify(MyLevelSearchLayer, LevelSearchLayer){
    static void onModify(auto& self) {
        (void)self.setHookPriority("LevelSearchLayer::init", -2);
    }
    
    bool init(int p0){
        if(!LevelSearchLayer::init(p0))
            return false;

        if (this->getChildByID("customBackground")) {
			return true;
		}

		auto bg = this->getChildByID("background");
        auto levelSearchBg = this->getChildByType<CCScale9Sprite>(0);
        auto levelSearchBarBg = this->getChildByType<CCScale9Sprite>(1);
        auto quickSearchBg = this->getChildByType<CCScale9Sprite>(2);
        auto diffFiltersBg = this->getChildByType<CCScale9Sprite>(3);
        auto lengthFiltersBg = this->getChildByType<CCScale9Sprite>(4);
        ccColor3B black = { 0, 0, 0 };

		bg->setVisible(false);

        levelSearchBg->setColor(black);
        levelSearchBg->setOpacity(127);

        levelSearchBarBg->setColor(black);

        quickSearchBg->setColor(black);
        quickSearchBg->setOpacity(127);

        diffFiltersBg->setColor(black);
        diffFiltersBg->setOpacity(127);

        lengthFiltersBg->setColor(black);
        lengthFiltersBg->setOpacity(127);

		CustomBackground *cbg = CustomBackground::create();
		cbg->setZOrder(-3);
		this->addChild(cbg);
		this->updateLayout();

        return true;
    }
};