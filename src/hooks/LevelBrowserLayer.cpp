#include <Geode/Geode.hpp>
#include "../CustomBackground.hpp"
#include <Geode/modify/LevelBrowserLayer.hpp>
using namespace geode::prelude;

class $modify(MyLevelBrowserLayer, LevelBrowserLayer){
    static void onModify(auto& self) {
        (void)self.setHookPriority("LevelBrowserLayer::init", -2);
    }

    bool init(GJSearchObject* p0) {
		if (!LevelBrowserLayer::init(p0)) {
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