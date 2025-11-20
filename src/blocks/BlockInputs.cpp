#include "BlockInputs.h"
#include <vector>

const std::vector<SingularBlockInput*>& BlockInputs::getAllInputs() {
    return _rawListData;
}