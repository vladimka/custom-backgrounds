#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSelectLayer.hpp>
#include "../CustomBackground.hpp"
using namespace geode::prelude;

class $modify(MyLevelSelectLayer, LevelSelectLayer){
    static void onModify(auto& self) {
        (void)self.setHookPriority("LevelSelectLayer::init", -2);
    }

    bool init(int page) {
		if (!LevelSelectLayer::init(page)) {
			return false;
		}

		if (this->getChildByID("customBackground")) {
			return true;
		}

		auto bg = static_cast<CCSprite*>(this->getChildByID("background"));
        auto g = this->getChildByID("ground-layer");

		// bg->setVisible(false);
		bg->setOpacity(50);
        g->setVisible(false);

        CustomBackground *cbg = CustomBackground::create();

		cbg->setZOrder(-3);

		this->addChild(cbg);
		this->updateLayout();

		return true;
	}
};