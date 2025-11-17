#pragma once

#include "ccTypes.h"
#include <vector>

class BlockCategory {
public:
    std::string id;
    cocos2d::ccColor3B categoryColor { 255, 255, 255 };
    std::string categoryName;

    BlockCategory(std::string id, cocos2d::ccColor3B color, std::string name) {
        this->id = id;
        categoryColor = color;
        categoryName = name;
    }
};