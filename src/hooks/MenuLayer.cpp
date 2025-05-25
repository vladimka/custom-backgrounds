#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "../CustomBackground.hpp"
using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
	static void onModify(auto& self) {
        (void)self.setHookPriority("MenuLayer::init", -2);
    }

	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		if (this->getChildByID("customBackground")) {
			return true;
		}

		auto bg = this->getChildByID("main-menu-bg");
		bg->setVisible(false);

		CustomBackground *cbg = CustomBackground::create();

		cbg->setZOrder(-3);
		this->addChild(cbg);
		this->updateLayout();

		return true;
	}
};