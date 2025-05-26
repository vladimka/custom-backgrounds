#include <Geode/Geode.hpp>
#include <Geode/modify/LoadingLayer.hpp>
#include "../CustomBackground.hpp"
using namespace geode::prelude;

class $modify(MyLoadingLayer, LoadingLayer){
    static void onModify(auto& self) {
        (void)self.setHookPriority("LoadingLayer::init", -2);
    }

    bool init(bool p0) {
		if (!LoadingLayer::init(p0)) {
			return false;
		}

		if (this->getChildByID("customBackground")) {
			return true;
		}

		auto bg = this->getChildByID("bg-texture");

		bg->setVisible(false);

        CustomBackground *cbg = CustomBackground::create();

		cbg->setZOrder(-3);

		this->addChild(cbg);
		this->updateLayout();

		return true;
	}
};