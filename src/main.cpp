#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

// Хук для главного меню
class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        // Добавляем кастомную кнопку в меню
        auto myButton = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
            this,
            menu_selector(MyMenuLayer::onMyButton)
        );

        auto menu = this->getChildByID("bottom-menu");
        if (menu) {
            menu->addChild(myButton);
            menu->updateLayout();
        }

        log::info("Мод загружен успешно!");
        
        return true;
    }

    void onMyButton(CCObject*) {
        FLAlertLayer::create(
            "Привет!",
            "Это пример мода на Geode для Geometry Dash!",
            "OK"
        )->show();
    }
};

// Хук для игрового процесса
class $modify(MyPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) {
            return false;
        }

        // Проверяем настройки мода
        bool featureEnabled = Mod::get()->getSettingValue<bool>("enable-feature");
        
        if (featureEnabled) {
            log::info("Функция мода активирована!");
            
            // Пример: изменение скорости игры
            float customSpeed = Mod::get()->getSettingValue<double>("custom-speed");
            CCDirector::sharedDirector()->getScheduler()->setTimeScale(customSpeed);
        }

        return true;
    }

    void onQuit() {
        // Восстанавливаем нормальную скорость при выходе
        CCDirector::sharedDirector()->getScheduler()->setTimeScale(1.0f);
        PlayLayer::onQuit();
    }
};
