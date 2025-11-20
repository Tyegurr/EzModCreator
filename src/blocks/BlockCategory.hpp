#pragma once

#include "ccTypes.h"
#include "BlockStructor.hpp"
#include <vector>

class BlockCategory {
protected:
    std::vector<BlockStructor*> _swatchList;
public:
    std::string id;
    cocos2d::ccColor3B categoryColor { 255, 255, 255 };
    std::string categoryName;

    BlockCategory(std::string id, cocos2d::ccColor3B color, std::string name) {
        this->id = std::move(id); //! Reminder: please don't directly assign it from the parameter. Use std::move instead. thanks @prevter
        categoryColor = color;
        categoryName = std::move(name);
    }
    const std::vector<BlockStructor*>& getAllSwatches() const;
    void addBlockSwatch(BlockStructor* ref);
};