#include "EnumCategory.h"
#include "../../BlockMapper.h"

void setupCategory_Enum() {
    BlockCategory* enumCategory = new BlockCategory("category_enum", { 0, 110, 255 }, "Enum");
    BlockMapper::get()->createNewCategoryFromInstance(enumCategory);
}