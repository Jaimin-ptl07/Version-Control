#include "branch.h"
#include <fstream>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

std::string getCurrentBranch() {
    std::ifstream branchFile("data/current_branch");
    if (!branchFile.is_open()) {
        return "main";
    }
    std::string branchName;
    std::getline(branchFile, branchName);
    return branchName;
}

void createBranch(const std::string& branchName, const std::string& commitHash) {
    std::ofstream branchFile("data/branches/" + branchName);
    branchFile << commitHash;
    branchFile.close();
}

std::string getBranchCommit(const std::string& branchName) {
    std::ifstream branchFile("data/branches/" + branchName);
    if (!branchFile.is_open()) {
        throw std::runtime_error("Branch not found.");
    }
    std::string commitHash;
    std::getline(branchFile, commitHash);
    return commitHash;
}

void mergeBranch(const std::string& sourceBranch, const std::string& targetBranch) {
    // Merge logic can be extended (conflict handling, etc.)
    std::string sourceCommit = getBranchCommit(sourceBranch);
    createBranch(targetBranch, sourceCommit);  // For now, just fast-forward merge
}
