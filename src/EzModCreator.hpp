#pragma once

#include "ui/ModListPopup.h"

class EzModCreator {
private:
    static EzModCreator* instancePtr;
    EzModCreator() {}

    bool _modListLayerOpen = false;
    ModListPopup* _modListPopup;
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