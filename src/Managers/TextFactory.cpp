#include "TextFactory.h"

TextFactory* TextFactory::instancePtr = nullptr;
TextFactory* TextFactory::get() {
    if (instancePtr == nullptr) {
        instancePtr = new TextFactory();
    }
    return instancePtr;
}

void TextFactory::addEntry(std::string name, std::string contents) {
    TextFactoryEntry entry { name, contents };
    _rawEntries.push_back(entry);
    _nameToEntry.insert({ name, _rawEntries.back() });
}
TextFactoryEntry TextFactory::retrieveEntry(std::string name) {
    return _nameToEntry[name];
}