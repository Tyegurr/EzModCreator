#include "StructCategory.h"
#include "../../BlockMapper.h"

void setupCategory_Struct() {
    BlockCategory* structCategory = new BlockCategory("category_struct", { 0, 200, 80 }, "Struct");
    BlockMapper::get()->createNewCategoryFromInstance(structCategory);
}