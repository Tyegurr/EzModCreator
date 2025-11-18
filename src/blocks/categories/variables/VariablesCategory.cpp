#include "VariablesCategory.h"
#include "../../BlockMapper.h"

void setupCategory_Variables() {
    BlockCategory* variablesCategory = new BlockCategory("category_variables", { 255, 80, 80 }, "Vars");
    BlockMapper::get()->createNewCategoryFromInstance(variablesCategory);
}