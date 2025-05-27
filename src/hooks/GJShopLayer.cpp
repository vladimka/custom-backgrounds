#include <Geode/modify/GJShopLayer.hpp>
#include <Geode/Geode.hpp>
#include "../CustomBackground.hpp"
using namespace geode::prelude;

class $modify(MyGJShopLayer, GJShopLayer){
    static void onModify(auto& self) {
        (void)self.setHookPriority("GJShopLayer::init", -2);
    }

    bool init(ShopType p0) {
		if (!GJShopLayer::init(p0)) {
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