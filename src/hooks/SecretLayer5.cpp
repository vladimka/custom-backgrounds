#include <Geode/modify/SecretLayer5.hpp>
#include <Geode/Geode.hpp>
#include "../CustomBackground.hpp"
using namespace geode::prelude;

class $modify(MySecretLayer5, SecretLayer5){
    static void onModify(auto& self) {
        (void)self.setHookPriority("SecretLayer5::init", -2);
    }

    bool init() {
		if (!SecretLayer5::init()) {
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