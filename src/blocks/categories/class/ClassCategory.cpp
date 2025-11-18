#include "ClassCategory.h"
#include "../../BlockMapper.h"

void setupCategory_Class() {
    BlockCategory* classCategory = new BlockCategory("category_class", { 42, 14, 250 }, "Class");
    BlockMapper::get()->createNewCategoryFromInstance(classCategory);
}