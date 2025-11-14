#pragma once

#include "ui/ModListLayer.h"

class EzModCreator {
private:
    static EzModCreator* instancePtr;
    EzModCreator() {}

    bool _modListLayerOpen = false;
    ModListLayer* _modListLayer;
public:

    EzModCreator(const EzModCreator& obj) = delete;
    static EzModCreator* get() {
        if (instancePtr == nullptr) {
            instancePtr = new EzModCreator();
        }
        return instancePtr;
    }

    void OpenModListLayer();
    void CloseModListLayer();
};