#include "toolRegistry.h"

#include <cassert>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <string>

namespace {

std::string readText(const std::filesystem::path& path) {
    std::ifstream input(path, std::ios::binary);
    return {std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>()};
}

} // namespace

int main() {
    const auto suffix = std::to_string(std::chrono::steady_clock::now().time_since_epoch().count());
    const std::filesystem::path home = std::filesystem::temp_directory_path() /
        ("toolbox-settings-contract-" + suffix);
    std::filesystem::create_directories(home);

    ToolDraft created{
        .name = "Acme",
        .description = "Startet Acme.",
        .luaScript = "error('must be replaced')",
        .iconBase64 = {},
        .timeoutSeconds = 30,
        .templateType = "program",
        .templateTarget = R"(C:\Program Files\Acme\Acme.exe)",
    };
    const auto creation = ToolRegistry::createTool(home, created);
    assert(creation.success);

    const auto oldPath = ToolRegistry::toolboxDirectory(home) / "Acme";
    const auto toolboxRoot = ToolRegistry::toolboxDirectory(home);
    const auto preparedStage = toolboxRoot / ".toolbox-update-101";
    const auto preparedJournal = toolboxRoot / ".toolbox-transaction-101.json";
    std::filesystem::copy(oldPath, preparedStage, std::filesystem::copy_options::recursive);
    std::ofstream(preparedJournal) <<
        R"({"version":1,"id":"101","originalName":"Acme","targetName":"Acme Website"})";
    ToolRegistry::loadTools(home);
    assert(std::filesystem::exists(oldPath));
    assert(!std::filesystem::exists(preparedStage));
    assert(!std::filesystem::exists(preparedJournal));

    const auto movedStage = toolboxRoot / ".toolbox-update-102";
    const auto movedBackup = toolboxRoot / ".toolbox-backup-102";
    const auto movedJournal = toolboxRoot / ".toolbox-transaction-102.json";
    std::filesystem::copy(oldPath, movedStage, std::filesystem::copy_options::recursive);
    std::ofstream(movedJournal) <<
        R"({"version":1,"id":"102","originalName":"Acme","targetName":"Acme Website"})";
    std::filesystem::rename(oldPath, movedBackup);
    ToolRegistry::loadTools(home);
    assert(std::filesystem::exists(oldPath));
    assert(!std::filesystem::exists(movedStage));
    assert(!std::filesystem::exists(movedBackup));
    assert(!std::filesystem::exists(movedJournal));

    const auto mismatchedBackup = toolboxRoot / ".toolbox-backup-104";
    const auto mismatchedJournal = toolboxRoot / ".toolbox-transaction-wrong.json";
    std::filesystem::copy(oldPath, mismatchedBackup, std::filesystem::copy_options::recursive);
    std::ofstream(mismatchedJournal) <<
        R"({"version":1,"id":"104","originalName":"Acme","targetName":"Acme Website"})";
    ToolRegistry::loadTools(home);
    assert(std::filesystem::exists(mismatchedBackup));
    assert(std::filesystem::exists(mismatchedJournal));

    const auto outsideTool = home / "outside-tool";
    std::filesystem::create_directory(outsideTool);
    std::ofstream(outsideTool / "start.lua") << "print('outside')";
    assert(!ToolRegistry::getToolDetails(home, outsideTool).success);

    const auto orphanPath = ToolRegistry::toolboxDirectory(home) / ".toolbox-update-orphan";
    std::filesystem::create_directory(orphanPath);
    std::ofstream(orphanPath / "start.lua") << "print('orphan')";
    const auto visibleTools = ToolRegistry::loadTools(home);
    assert(visibleTools.size() == 1);
    assert(visibleTools.front().name == "Acme");
    std::ofstream(oldPath / "asset.txt") << "preserve me";

    const auto loaded = ToolRegistry::getToolDetails(home, oldPath);
    assert(loaded.success);
    assert(loaded.details.name == "Acme");
    assert(loaded.details.description == "Startet Acme.");
    assert(loaded.details.timeoutSeconds == 30);
    assert(loaded.details.templateType == "program");
    assert(loaded.details.templateTarget == R"(C:\Program Files\Acme\Acme.exe)");
    assert(loaded.details.luaScript.find("start") != std::string::npos);
    assert(loaded.details.luaScript.find("must be replaced") == std::string::npos);

    ToolUpdateDraft update{
        .name = "Acme Website",
        .description = "Öffnet die Acme-Website.",
        .luaScript = "error('must also be replaced')",
        .timeoutSeconds = 45,
        .templateType = "website",
        .templateTarget = "https://www.example.com/docs",
    };
    const auto updated = ToolRegistry::updateTool(home, oldPath, update);
    assert(updated.success);

    const auto newPath = ToolRegistry::toolboxDirectory(home) / "Acme Website";
    assert(updated.toolPath == newPath);
    assert(!std::filesystem::exists(oldPath));
    assert(readText(newPath / "asset.txt") == "preserve me");

    const auto committedBackup = toolboxRoot / ".toolbox-backup-103";
    const auto committedJournal = toolboxRoot / ".toolbox-transaction-103.json";
    std::filesystem::copy(newPath, committedBackup, std::filesystem::copy_options::recursive);
    std::ofstream(committedJournal) <<
        R"({"version":1,"id":"103","originalName":"Acme","targetName":"Acme Website"})";
    ToolRegistry::loadTools(home);
    assert(std::filesystem::exists(newPath));
    assert(!std::filesystem::exists(committedBackup));
    assert(!std::filesystem::exists(committedJournal));

    const auto reloaded = ToolRegistry::getToolDetails(home, newPath);
    assert(reloaded.success);
    assert(reloaded.details.name == "Acme Website");
    assert(reloaded.details.description == "Öffnet die Acme-Website.");
    assert(reloaded.details.timeoutSeconds == 45);
    assert(reloaded.details.templateType == "website");
    assert(reloaded.details.templateTarget == "https://www.example.com/docs");
    assert(reloaded.details.luaScript.find("https://www.example.com/docs") != std::string::npos);
    assert(reloaded.details.luaScript.find("must also be replaced") == std::string::npos);

    std::ofstream(newPath / "tool.json") << R"({"version":1,"type":"bogus","target":"ignored"})";
    const auto invalidMetadata = ToolRegistry::getToolDetails(home, newPath);
    assert(invalidMetadata.success);
    assert(invalidMetadata.details.templateType == "lua");
    assert(invalidMetadata.details.templateTarget.empty());

    std::filesystem::remove(newPath / "tool.json");
    const auto legacy = ToolRegistry::getToolDetails(home, newPath);
    assert(legacy.success);
    assert(legacy.details.templateType == "lua");
    assert(legacy.details.templateTarget.empty());

    const auto invalid = ToolRegistry::updateTool(home, newPath, ToolUpdateDraft{
        .name = "../escape",
        .description = "invalid",
        .luaScript = "print('invalid')",
        .timeoutSeconds = 30,
        .templateType = "lua",
    });
    assert(!invalid.success);
    assert(std::filesystem::exists(newPath));
    assert(readText(newPath / "description.txt") == "Öffnet die Acme-Website.");

    std::filesystem::remove_all(home);
    return 0;
}
