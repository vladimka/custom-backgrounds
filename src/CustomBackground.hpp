#pragma once

#include <Geode/Geode.hpp>
using namespace geode::prelude;

class CustomBackground : public CCNode{
public:
    std::filesystem::path m_bgPath = Mod::get()->getSettingValue<std::filesystem::path>("bg-path");
    bool m_colorFeature = Mod::get()->getSettingValue<bool>("color-feature");
    ccColor3B m_color = Mod::get()->getSettingValue<ccColor3B>("color");

	static CustomBackground* create(){
        auto ret = new CustomBackground();

        if (ret->init()) {
            ret->autorelease();

            return ret;
        }

        CC_SAFE_DELETE(ret);

        log::info("Failed to create CustomBackground instance");

        return nullptr;
    };
protected:
	bool init();
};