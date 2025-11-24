#include "BlockOutputs.h"
#include "BlockParameter.h"
#include <memory>
#include <vector>

const std::vector<std::shared_ptr<SingularBlockOutput>>& BlockOutputs::getAllOutputs() {
    return _rawListData;
}

const SingularBlockOutput& BlockOutputs::getOutputOfIndex(int idx) {
    return *_rawListData[idx];
}

// STARRY EYES IN THE PAST,
// STARRY HOPES UP IN THE SKY!

// address me
void BlockOutputs::addOutput(std::string name, std::string description, bool isMethod, bool isStaticMethod, std::vector<BlockParameter> parameters) {
    _rawListData.push_back(std::make_shared<SingularBlockOutput>(name, description, isMethod, isStaticMethod, parameters));
}