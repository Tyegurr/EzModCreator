#include "FunctionsCategory.h"
#include "../../BlockMapper.h"

void setupCategory_Functions() {
    BlockCategory* functionsCategory = new BlockCategory("category_functions", { 255, 110, 255 }, "Funcs");
    BlockMapper::get()->createNewCategoryFromInstance(functionsCategory);
}