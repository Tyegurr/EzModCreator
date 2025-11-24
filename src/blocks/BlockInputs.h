#pragma once
#include "BlockOutputs.h"
#include <vector>

class SingularBlockInput {
public:
    SingularBlockInput() {}
};

class BlockInputs {
protected:
    std::vector<SingularBlockInput*> _rawListData;
public:
    BlockInputs() {}

    const std::vector<SingularBlockInput*>& getAllInputs();
    const SingularBlockInput& getInputOfIndex(int idx);
};