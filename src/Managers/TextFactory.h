#pragma once

#include <vector>
#include <map>
#include <string>

struct TextFactoryEntry {
    std::string name;
    std::string contents;
};

class TextFactory {
private:
    static TextFactory* instancePtr;
    TextFactory() {}

    std::map<std::string, TextFactoryEntry> _nameToEntry;
    std::vector<TextFactoryEntry> _rawEntries;
public:
    TextFactory(const TextFactory& obj) = delete;
    static TextFactory* get();

    void addEntry(std::string name, std::string contents);
    TextFactoryEntry retrieveEntry(std::string name);
};