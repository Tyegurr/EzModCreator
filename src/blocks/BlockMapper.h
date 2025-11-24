#pragma once

#include <vector>
#include <unordered_map>
#include "BlockCategory.hpp"
#include "categories/categories.h"

struct category_metadata {
    std::string id;
    cocos2d::ccColor3B color;
    std::string name;
};

/// Block Mapper - Stores all block categories and their respective blocks
class BlockMapper {
protected:
    static BlockMapper* instancePtr;
    BlockMapper() {}
    
    std::vector<BlockCategory*> _categoryListRaw;
    std::unordered_map<std::string, BlockCategory*> _idToCategory;
    std::vector<category_metadata> _metadataListRaw; 
public:
    BlockMapper(const BlockMapper& obj) = delete;
    static BlockMapper* get();

    /// Creates a new block category with it's respective parameters.
    BlockCategory* createNewCategory(std::string id, cocos2d::ccColor3B categoryColor, std::string categoryName);
    /// Creates a new block category from an instance of a BlockCategory class.
    BlockCategory* createNewCategoryFromInstance(BlockCategory* instance);
    /// Gets a block category from it's respective id.
    const BlockCategory& getBlockCategoryFromId(std::string id) const;

    ///  Gets metadata for each category in a vector
    std::vector<category_metadata> getAllCategoryMetadata();

    /// Initializes all block categories and stuff
    void initAllKnownEverything();
    /// Cleans up everything
    void cleanup();
};