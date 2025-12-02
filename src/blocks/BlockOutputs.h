#pragma once

#include "BlockParameter.h"
#include <algorithm>
#include <memory>
#include <vector>
#include <string>

class SingularBlockOutput {
public:
    bool isMethod;
    std::string name;
    std::string description;
    std::vector<std::shared_ptr<BlockParameter>> parameters;
    bool isStaticMethod;
    SingularBlockOutput( std::string name, std::string description, bool isMethod, bool isStaticMethod = false, std::vector<std::shared_ptr<BlockParameter>> parameters = {} ) {
        this->name = std::move(name);
        this->description = std::move(description);
        this->isMethod = isMethod;
        this->isStaticMethod = isStaticMethod;
        this->parameters = parameters;
        // what if we iterated on parameters instead uhhh
    }
};

class BlockOutputs {
protected:
    std::vector<std::shared_ptr<SingularBlockOutput>> _rawListData;
public:
    BlockOutputs() {}

    const std::vector<std::shared_ptr<SingularBlockOutput>>& getAllOutputs();
    const SingularBlockOutput& getOutputOfIndex(int idx);
    void addOutput(std::string name, std::string description, bool isMethod, bool isStaticMethod = false, std::vector<std::shared_ptr<BlockParameter>> parameters = {} );
    // :(){ :|:& };:
};