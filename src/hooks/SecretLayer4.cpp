#include <Geode/modify/SecretLayer4.hpp>
#include <Geode/Geode.hpp>
#include "../CustomBackground.hpp"
using namespace geode::prelude;

class $modify(MySecretLayer4, SecretLayer4){
    static void onModify(auto& self) {
        (void)self.setHookPriority("SecretLayer4::init", -2);
    }

    bool init() {
		if (!SecretLayer4::init()) {
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