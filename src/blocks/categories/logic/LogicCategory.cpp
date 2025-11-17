#include "LogicCategory.h"
#include "../../BlockMapper.h"

void setupCategory_Logic() {
    BlockCategory* logicCategory = new BlockCategory("category_logic", { 255, 0, 157 }, "Logic");
    BlockMapper::get()->createNewCategoryFromInstance(logicCategory);
}