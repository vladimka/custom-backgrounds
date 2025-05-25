#include <Geode/Geode.hpp>
#include "../CustomBackground.hpp"
#include <Geode/modify/LevelInfoLayer.hpp>
using namespace geode::prelude;

class $modify(MyLevelInfoLayer, LevelInfoLayer){
    static void onModify(auto& self) {
        (void)self.setHookPriority("LevelInfoLayer::init", -2);
    }

    bool init(GJGameLevel* level, bool challenge) {
		if (!LevelInfoLayer::init(level, challenge)) {
			return false;
		}

		if (this->getChildByID("customBackground")) {
			return true;
		}

		auto bg = this->getChildByID("background");
		bg->setVisible(false);

		CustomBackground *cbg = CustomBackground::create();
		cbg->setZOrder(-3);
		this->addChild(cbg);
		this->updateLayout();

		return true;
	}
};