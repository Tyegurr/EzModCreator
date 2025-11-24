#pragma once
#include "HookBlockStructor.h"
#include <Geode/binding/FLAlertLayer.hpp>

class AccountHelpLayerHookBlockStructor : public HookBlockStructor {
protected:
    AccountHelpLayerHookBlockStructor() {}
public:
    static AccountHelpLayerHookBlockStructor* createAsSwatch() {
        AccountHelpLayerHookBlockStructor* block = new AccountHelpLayerHookBlockStructor();
        block->isASwatch = true;
        block->name = "Hook AccountHelpLayer";

        block->outputs->addOutput("customSetup", "No description", true);
        block->outputs->addOutput("layerHidden", "No description", true);
        block->outputs->addOutput("accountStatusChanged", "No description", true);
        block->outputs->addOutput("FLAlert_Clicked", "No description", true, { {"p0", nullptr}, {"p1", false} });
        // doUnlink() is Android Only
        // exitLayer() is Android Only
        block->outputs->addOutput("onAccountManagement", "No description", true, { {"sender", nullptr} });
        block->outputs->addOutput("onReLogin", "No description", true, { {"sender", nullptr} });
        block->outputs->addOutput("onUnlink", "No description", true, { {"sender", nullptr} });
        block->outputs->addOutput("updatePage", "No description", true);
        // verifyUnlink() is Out-Of-Line on windows
        return block;
    }
};