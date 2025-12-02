#pragma once

#include <any>
#include <string>
#include <memory>

#define SharedBlockParam std::make_shared<BlockParameter>

typedef struct {
    std::string name;
    std::string description;
    std::string valueTypeAsString;
    std::any value;
} BlockParameter;