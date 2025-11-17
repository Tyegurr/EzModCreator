#include "MathCategory.h"
#include "../../BlockMapper.h"

void setupCategory_Math() {
    BlockCategory* mathCategory = new BlockCategory("category_math", { 48, 255, 255 }, "Math");
    BlockMapper::get()->createNewCategoryFromInstance(mathCategory);
}