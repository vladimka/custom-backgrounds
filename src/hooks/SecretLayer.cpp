#include <Geode/modify/SecretLayer.hpp>
#include <Geode/Geode.hpp>
#include "../CustomBackground.hpp"
using namespace geode::prelude;

class $modify(MySecretLayer, SecretLayer){
    static void onModify(auto& self) {
        (void)self.setHookPriority("SecretLayer::init", -2);
    }

    bool init() {
		if (!SecretLayer::init()) {
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