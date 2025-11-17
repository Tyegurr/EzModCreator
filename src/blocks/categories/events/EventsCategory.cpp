#include "EventsCategory.h"
#include "../../BlockMapper.h"

void setupCategory_Events() {
    BlockCategory* eventsCategory = new BlockCategory("category_events", { 255, 128, 0 }, "Events");
    BlockMapper::get()->createNewCategoryFromInstance(eventsCategory);
}