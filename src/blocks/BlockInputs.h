#pragma once
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
    SingularBlockInput* getInputOfIndex(int idx);
};