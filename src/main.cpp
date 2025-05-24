#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/loader/SettingV3.hpp>
using namespace geode::prelude;

auto backgroundPath = Mod::get()->getSettingValue<std::filesystem::path>("bg-path");

$execute {
    listenForSettingChanges("bg-path", [](std::filesystem::path) {
        backgroundPath = Mod::get()->getSettingValue<std::filesystem::path>("bg-path");
    });
}

class CustomBackground : public CCNode{
protected:
	bool init(){
		if(!CCNode::init())
			return false;

		this->setID("customBackground");

		auto winSize = CCDirector::get()->getWinSize();

		this->setContentSize(winSize);
		this->setAnchorPoint({ 0.f, 0.f });
		this->setID("custom-bg"_spr);

		if(!std::filesystem::exists(backgroundPath)){
			auto label = CCLabelBMFont::create("Images does not exists!", "bigFont.fnt"); 
			label->setPosition(winSize/2);
			this->addChild(label);
			return true;
		}

		auto path = backgroundPath.string().c_str();
		auto sprite = CCSprite::create(path);
		if (!sprite) {
			return false;
		}

		auto scaleX =  winSize.width / sprite->getContentWidth();
		auto scaleY =  winSize.height / sprite->getContentHeight();

		log::info("Images scale: {}, {}", scaleX, scaleY);

		sprite->setScaleX(scaleX);
		sprite->setScaleY(scaleY);
		sprite->setAnchorPoint({ 0, 0 });
		sprite->setPosition({ 0, 0 });

		this->addChild(sprite);
		this->updateLayout();

		return true;
	}
public:
	static CustomBackground* create(){
		auto ret = new CustomBackground();
		if (ret->init()) {
			ret->autorelease();
			return ret;
		}
		CC_SAFE_DELETE(ret);
		log::info("Failed to create CustomBackground instance");
		return nullptr;
	}
};

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