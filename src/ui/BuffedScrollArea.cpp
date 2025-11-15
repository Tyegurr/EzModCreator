#include "BuffedScrollArea.h"

void BuffedScrollArea::updateGeom() {
}
bool BuffedScrollArea::init(bool scrollbarVisible) {
    if (!CCNode::init()) return false;

    updateGeom();
    return true;
}

BuffedScrollArea* BuffedScrollArea::create(bool scrollbarVisible) {
    BuffedScrollArea* node = new BuffedScrollArea();
    node->init(scrollbarVisible);
    return node;
}

void BuffedScrollArea::update(float delta) {
    updateGeom();
}