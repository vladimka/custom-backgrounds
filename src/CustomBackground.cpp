#include "CustomBackground.hpp"

bool CustomBackground::init(){
    if(!CCNode::init())
		return false;

    this->setID("customBackground");

    auto winSize = CCDirector::get()->getWinSize();

    this->setContentSize(winSize);
    this->setAnchorPoint({ 0.f, 0.f });
    this->setID("custom-bg"_spr);

    if(!std::filesystem::exists(m_bgPath)){
        log::info("Failed to find iamge");

        auto label = CCLabelBMFont::create("Images does not exists!", "bigFont.fnt"); 

        label->setPosition(winSize/2);
        this->addChild(label);

        return true;
    }

    auto path = m_bgPath.string().c_str();
    auto sprite = CCSprite::create(path);

    if (!sprite) {
        log::info("Failed to create sprite");

        auto label = CCLabelBMFont::create("Could not create background!", "bigFont.fnt"); 

        label->setPosition(winSize/2);
        this->addChild(label);
        
        return true;
    }

    auto scaleX =  winSize.width / sprite->getContentWidth();
    auto scaleY =  winSize.height / sprite->getContentHeight();

    log::info("Images scale: {}, {}", scaleX, scaleY);

    sprite->setScaleX(scaleX);
    sprite->setScaleY(scaleY);
    sprite->setAnchorPoint({ 0, 0 });
    sprite->setPosition({ 0, 0 });
    
    if(m_colorFeature)
        sprite->setColor(m_color);

    this->addChild(sprite);
    this->updateLayout();

    log::info("Created CustomBackground from image: {}", path);

    return true;
}