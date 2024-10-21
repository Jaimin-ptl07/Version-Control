#ifndef COMMIT_H
#define COMMIT_H

#include <string>
#include <vector>

struct Commit {
    std::string hash;
    std::string message;
    std::string author;
    std::vector<std::string> blobHashes;  // References to file blobs
};

std::string createCommit(const std::string& message, const std::string& author, const std::vector<std::string>& blobHashes);
Commit loadCommit(const std::string& commitHash);

#endif // COMMIT_H
