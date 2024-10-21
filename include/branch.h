#ifndef BRANCH_H
#define BRANCH_H

#include <string>

std::string getCurrentBranch();
void createBranch(const std::string& branchName, const std::string& commitHash);
std::string getBranchCommit(const std::string& branchName);
void mergeBranch(const std::string& sourceBranch, const std::string& targetBranch);

#endif // BRANCH_H
