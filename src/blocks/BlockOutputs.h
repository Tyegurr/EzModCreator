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
    std::vector<BlockParameter> parameters;
    bool isStaticMethod;
    SingularBlockOutput( std::string name, std::string description, bool isMethod, bool isStaticMethod = false, std::vector<BlockParameter> parameters = {} ) {
        this->name = std::move(name);
        this->description = std::move(description);
        this->isMethod = isMethod;
        this->isStaticMethod = isStaticMethod;
        this->parameters = std::move(parameters);
    }
};

class BlockOutputs {
protected:
    std::vector<std::shared_ptr<SingularBlockOutput>> _rawListData;
public:
    BlockOutputs() {}

    const std::vector<std::shared_ptr<SingularBlockOutput>>& getAllOutputs();
    const SingularBlockOutput& getOutputOfIndex(int idx);
    void addOutput(std::string name, std::string description, bool isMethod, bool isStaticMethod = false, std::vector<BlockParameter> parameters = {});
    // :(){ :|:& };:
};