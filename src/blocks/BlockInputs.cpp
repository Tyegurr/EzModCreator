#include "BlockInputs.h"
#include <vector>

const std::vector<SingularBlockInput*>& BlockInputs::getAllInputs() {
    return _rawListData;
}
const SingularBlockInput& BlockInputs::getInputOfIndex(int idx) {
    return *_rawListData[idx];
}