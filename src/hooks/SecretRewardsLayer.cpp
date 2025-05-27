#include <Geode/modify/SecretRewardsLayer.hpp>
#include <Geode/Geode.hpp>
#include "../CustomBackground.hpp"
using namespace geode::prelude;

class $modify(MySecretRewardsLayer, SecretRewardsLayer){
    static void onModify(auto& self) {
        (void)self.setHookPriority("SecretRewardsLayer::init", -2);
    }

    bool init(bool p0){
        if(!SecretRewardsLayer::init(p0))
            return false;

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