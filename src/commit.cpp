#include "commit.h"
#include <fstream>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

std::string createCommit(const std::string& message, const std::string& author, const std::vector<std::string>& blobHashes) {
    std::string commitHash = std::to_string(std::hash<std::string>{}(message + author));

    fs::create_directories("data/commits");

    std::ofstream commitFile("data/commits/" + commitHash);
    if (commitFile.is_open()) {
        commitFile << "Author: " << author << "\n";
        commitFile << "Message: " << message << "\n";
        commitFile << "Blobs:\n";
        for (const auto& blobHash : blobHashes) {
            commitFile << blobHash << "\n";
        }
        commitFile.close();
    }
    return commitHash;
}

Commit loadCommit(const std::string& commitHash) {
    std::ifstream commitFile("data/commits/" + commitHash);
    if (!commitFile.is_open()) {
        throw std::runtime_error("Commit not found.");
    }

    Commit commit;
    commit.hash = commitHash;
    std::string line;
    while (std::getline(commitFile, line)) {
        if (line.find("Author:") != std::string::npos) {
            commit.author = line.substr(8);
        } else if (line.find("Message:") != std::string::npos) {
            commit.message = line.substr(9);
        } else if (!line.empty()) {
            commit.blobHashes.push_back(line);
        }
    }
    return commit;
}
