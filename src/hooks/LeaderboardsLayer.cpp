#include <Geode/modify/LeaderboardsLayer.hpp>
#include <Geode/Geode.hpp>
#include "../CustomBackground.hpp"
using namespace geode::prelude;

class $modify(MyLeaderboardsLayer, LeaderboardsLayer){
    static void onModify(auto& self) {
        (void)self.setHookPriority("LeaderboardsLayer::init", -2);
    }

    bool init(LeaderboardState p0) {
		if (!LeaderboardsLayer::init(p0)) {
			return false;
		}

		if (this->getChildByID("customBackground")) {
			return true;
		}

		auto bg = this->getChildByType<CCSprite>(0);
		bg->setVisible(false);

		CustomBackground *cbg = CustomBackground::create();
		cbg->setZOrder(-3);
		this->addChild(cbg);
		this->updateLayout();

		return true;
	}
};