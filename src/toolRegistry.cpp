#include "toolRegistry.h"

#include <cppcodec/base64_rfc4648.hpp>

#include <fstream>
#include <iostream>

std::filesystem::path ToolRegistry::toolboxDirectory(const std::filesystem::path& userPath) {
    return userPath / ".Toolbox";
}

bool ToolRegistry::ensureToolboxDirectory(const std::filesystem::path& userPath) {
    const std::filesystem::path toolboxPath = toolboxDirectory(userPath);
    if (std::filesystem::exists(toolboxPath)) {
        return true;
    }

    try {
        if (std::filesystem::create_directory(toolboxPath)) {
            std::cout << ".Toolbox Verzeichnis wurde erstellt." << std::endl;
            return true;
        }

        std::cerr << "Fehler beim Erstellen des .Toolbox Verzeichnisses." << std::endl;
        return false;
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Filesystem-Fehler: " << e.what() << std::endl;
        return false;
    }
}

std::vector<ToolboxItem> ToolRegistry::loadTools(const std::filesystem::path& userPath) {
    std::vector<ToolboxItem> items;
    const std::filesystem::path toolboxDir = toolboxDirectory(userPath);

    if (!std::filesystem::exists(toolboxDir) || !std::filesystem::is_directory(toolboxDir)) {
        std::cerr << "Fehler: Das Verzeichnis .Toolbox existiert nicht." << std::endl;
        return items;
    }

    int id = 0;
    for (const auto& entry : std::filesystem::directory_iterator(toolboxDir)) {
        if (!entry.is_directory()) {
            continue;
        }

        ToolboxItem item;
        item.id = std::to_string(id++);
        item.name = entry.path().filename().string();
        item.path = entry.path().string();

        encodeIcon(entry.path() / "icon.png", item);

        const std::filesystem::path descriptionFile = entry.path() / "description.txt";
        if (std::filesystem::exists(descriptionFile)) {
            std::ifstream descFile(descriptionFile);
            item.description.assign(std::istreambuf_iterator<char>(descFile), std::istreambuf_iterator<char>());
        }

        const std::filesystem::path luaScript = entry.path() / "start.lua";
        if (std::filesystem::exists(luaScript)) {
            item.lua_script_path_string = luaScript.string();
        }

        items.push_back(std::move(item));
    }

    return items;
}

void ToolRegistry::encodeIcon(const std::filesystem::path& imagePath, ToolboxItem& item) {
    std::ifstream file(imagePath, std::ios::binary | std::ios::ate);
    if (!file) {
        std::cerr << "Fehler beim Oeffnen des PNG-Bildes: " << imagePath << std::endl;
        return;
    }

    const std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<unsigned char> fileData(fileSize);
    if (!file.read(reinterpret_cast<char*>(fileData.data()), fileSize)) {
        std::cerr << "Fehler beim Lesen des PNG-Bildes: " << imagePath << std::endl;
        return;
    }

    item.icon = "data:image/png;base64," + cppcodec::base64_rfc4648::encode(fileData);
}
