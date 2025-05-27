#include <Geode/modify/GJGarageLayer.hpp>
#include <Geode/Geode.hpp>
#include "../CustomBackground.hpp"
using namespace geode::prelude;

class $modify(MyGJGarageLayer, GJGarageLayer){
    static void onModify(auto& self) {
        (void)self.setHookPriority("GJGarageLayer::init", -2);
    }

    bool init() {
		if (!GJGarageLayer::init()) {
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