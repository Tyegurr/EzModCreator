#include "HooksCategory.h"
#include "../../BlockMapper.h"

void setupCategory_Hooks() {
    BlockCategory* hooksCategory = new BlockCategory("category_hooks", { 255, 255, 0 }, "Hooks");
    BlockMapper::get()->createNewCategoryFromInstance(hooksCategory);
}