#include "ui.h"

bool isPointInsideRect(CCPoint point, CCRect area) {
    if (point.x >= area.origin.x && point.x <= (area.origin.x + area.size.width)) {
        return true;
    }
    return false;
}
bool isMouseInsideRect(CCRect area) {
    cocos2d::CCPoint mousePos = geode::cocos::getMousePos();
    return (mousePos.x >= area.origin.x && mousePos.x <= (area.origin.x + area.size.width)) && (mousePos.y >= area.origin.y && mousePos.y <= (area.origin.y + area.size.height));
}