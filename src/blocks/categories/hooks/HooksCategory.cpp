#include "HooksCategory.h"
#include "../../BlockMapper.h"

// here comes the shitstorm
#include "AccountHelpLayerHookBlockStructor.hpp"

void setupCategory_Hooks() {
    BlockCategory* hooksCategory = new BlockCategory("category_hooks", { 255, 255, 0 }, "Hooks");

    hooksCategory->addBlockSwatch(AccountHelpLayerHookBlockStructor::createAsSwatch());

    BlockMapper::get()->createNewCategoryFromInstance(hooksCategory);
}