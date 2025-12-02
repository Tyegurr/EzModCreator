#pragma once
#include "HookBlockStructor.h"
#include <Geode/binding/FLAlertLayer.hpp>

class AccountHelpLayerHookBlockStructor : public HookBlockStructor {
protected:
    AccountHelpLayerHookBlockStructor() : HookBlockStructor() {}
public:
    static AccountHelpLayerHookBlockStructor* createAsSwatch() {
        AccountHelpLayerHookBlockStructor* block = new AccountHelpLayerHookBlockStructor();
        block->isASwatch = true;
        block->name = "Hook AccountHelpLayer";

        block->outputs->addOutput("customSetup", "No description provided", true);
        block->outputs->addOutput("layerHidden", "No description provided", true);
        block->outputs->addOutput("accountStatusChanged", "No description provided", true);
        block->outputs->addOutput("FLAlert_Clicked", "Triggers when the user pressed a button on the alert that pops up.", true, false, {
            SharedBlockParam("layer", "No description provided", "FLAlertLayer*", nullptr),
            SharedBlockParam("btn2", "Tells whether the 2nd button was pressed or not", "bool", nullptr)
        });
        // doUnlink() is out of line on windows
        // exitLayer() is out of line on windows
        block->outputs->addOutput("onAccountManagement", "Triggers when the \"Account Management\" button is pressed.", true, false, {
            SharedBlockParam("sender", "No description provided", "cocos2d::CCObject*", nullptr)
        });
        block->outputs->addOutput("onRelogin", "No description provided", true, false, {
            SharedBlockParam("sender", "No description provided", "cocos2d::CCObject*", nullptr)
        });
        block->outputs->addOutput("onUnlink", "No description provided", true, false, {
            SharedBlockParam("sender", "No description provided", "cocos2d::CCObject*", nullptr)
        });
        block->outputs->addOutput("updatePage", "Updates the account help page.", true);
        // verifyUnlink() is out-of-line on windows

        return block;
    }
};