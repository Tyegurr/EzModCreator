#include "BlockMapper.h"
#include "BlockCategory.hpp"
#include "categories/class/ClassCategory.h"
#include "categories/hooks/HooksCategory.h"
#include "categories/struct/StructCategory.h"
#include "categories/variables/VariablesCategory.h"
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
const BlockCategory& BlockMapper::getBlockCategoryFromId(std::string id) const {
    if (_idToCategory.contains(id)) return *_idToCategory.at(id);
    return *new BlockCategory("unknown", {255, 255, 255}, "unknown block");
}

std::vector<category_metadata> BlockMapper::getAllCategoryMetadata() {
    return _metadataListRaw;
}

//initAllKnownEverything?? when did i write this wtf
void BlockMapper::initAllKnownEverything() {
    setupCategory_Hooks();
    setupCategory_Events();
    setupCategory_Logic();
    setupCategory_Math();
    setupCategory_Variables();
    setupCategory_Functions();
    setupCategory_Class();
    setupCategory_Struct();
    setupCategory_Enum();
}
void BlockMapper::cleanup() {
    //? collect my categories
    _categoryListRaw.clear();
    _idToCategory.clear();
}