#pragma once
#include "HookBlockStructor.h"

class AccountLayerHookBlockStructor : public HookBlockStructor {
protected:
    AccountLayerHookBlockStructor() {}
public:
    static AccountLayerHookBlockStructor* createAsSwatch() {
        AccountLayerHookBlockStructor* block = new AccountLayerHookBlockStructor();
        block->isASwatch = true;
        block->name = "Hook AccountLayer";

        block->outputs->addOutput("create", "No description", true, true);
        return block;
    }
};