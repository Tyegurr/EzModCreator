#include "BlockCategory.hpp"
#include "BlockStructor.hpp"
#include <vector>

const std::vector<BlockStructor*>& BlockCategory::getAllSwatches() const {
    return _swatchList;
}
void BlockCategory::addBlockSwatch(BlockStructor* ref) {
    ref->blockColor = categoryColor;
    _swatchList.push_back(ref);
}