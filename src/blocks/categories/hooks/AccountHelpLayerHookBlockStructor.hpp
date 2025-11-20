#pragma once
#include "HookBlockStructor.h"

class AccountHelpLayerHookBlockStructor : public HookBlockStructor {
protected:
    AccountHelpLayerHookBlockStructor() {}
public:
    static AccountHelpLayerHookBlockStructor* createAsSwatch() {
        AccountHelpLayerHookBlockStructor* block = new AccountHelpLayerHookBlockStructor();
        block->isASwatch = true;
        return block;
    }
};