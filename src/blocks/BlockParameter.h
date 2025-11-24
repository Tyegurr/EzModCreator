#pragma once

#include <any>
#include <string>
#include <typeinfo>

typedef struct {
    std::string name;
    std::any value;
} BlockParameter;