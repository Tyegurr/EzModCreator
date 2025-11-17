#include "BlockMapper.h"
#include "BlockCategory.hpp"
#include "categories/hooks/HooksCategory.h"
#include <vector>

BlockMapper* BlockMapper::instancePtr = nullptr;

BlockMapper* BlockMapper::get() {
    if (instancePtr == nullptr) {
        instancePtr = new BlockMapper();
    }
    return instancePtr;
}

BlockCategory* BlockMapper::createNewCategory(std::string id, cocos2d::ccColor3B categoryColor, std::string categoryName) {
    BlockCategory* category = new BlockCategory(id, categoryColor, categoryName);
    _categoryListRaw.push_back(category);
    _idToCategory.insert_or_assign(id, _categoryListRaw.back());
    _metadataListRaw.push_back({ id, categoryColor, categoryName });
    return _categoryListRaw.back();
}
BlockCategory* BlockMapper::createNewCategoryFromInstance(BlockCategory* instance) {
    _categoryListRaw.push_back(instance);
    _idToCategory.insert_or_assign(instance->id, _categoryListRaw.back());
    _metadataListRaw.push_back({instance->id, instance->categoryColor, instance->categoryName});
    return _categoryListRaw.back();
}
BlockCategory* BlockMapper::getBlockCategoryFromId(std::string id) {
    if (_idToCategory.contains(id)) return _idToCategory[id];
    return nullptr;
}

std::vector<category_metadata> BlockMapper::getAllCategoryMetadata() {
    return _metadataListRaw;
}

void BlockMapper::initAllKnownEverything() {
    //? zZZzz.. *SNORE*
    setupCategory_Hooks();
    setupCategory_Events();
    setupCategory_Logic();
    setupCategory_Math();
}
void BlockMapper::cleanup() {
    //? collect my categories im the blockerman
    _categoryListRaw.clear();
    _idToCategory.clear();
}