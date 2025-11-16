#pragma once

#include "ui/ModListPopup.h"
#include "ui/ModCreationLabLayer.h"

class EzModCreator {
private:
    static EzModCreator* instancePtr;
    EzModCreator() {}

    bool _modListLayerOpen = false;
    ModListPopup* _modListPopup;
    ModCreationLabLayer* _modCreationLabLayer;
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
    void setCreationLabLayerCurrent(ModCreationLabLayer* layer);
    ModCreationLabLayer* getCreationLabLayer();
};