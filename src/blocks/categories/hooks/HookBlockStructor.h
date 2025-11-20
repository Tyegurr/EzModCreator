#pragma once
#include "../../BlockStructor.hpp"
#include <vector>

enum Platform {
    PLATFORM_MacOSARM,
    PLATFORM_MacOSIntel,
    PLATFORM_Windows,
    PLATFORM_Android,
    PLATFORM_iOS
};

class HookBlockStructor : public BlockStructor {
protected:
    std::vector<Platform> _availablePlatforms;
    HookBlockStructor() {}
public:
    const std::vector<Platform>& getAvailablePlatforms();
};