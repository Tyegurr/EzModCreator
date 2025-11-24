// this main file acts like a hub for all the includes
#include "GameModifiers/MenuLayer.hpp"

#include "Geode/DefaultInclude.hpp"
#include "Managers/TextFactory.h"

$execute {
    TextFactory::addEntryToCurrentInstance("EN_NoModsFound", "No mods were found!");
    // pusab doesn't support the "¡" character but whateverss
    TextFactory::addEntryToCurrentInstance("ES_NoModsFound", "¡No se encantraron modificaciones!");

    /* ==== Mod Creation Labs ===== */
    /* Save button */
    TextFactory::addEntryToCurrentInstance("EN_SaveModButton", "Save");
    TextFactory::addEntryToCurrentInstance("ES_SaveModButton", "Guardar");
}