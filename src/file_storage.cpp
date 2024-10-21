#include "file_storage.h"
#include <openssl/sha.h>  // For SHA-256 hashing
#include <fstream>
#include <iomanip>
#include <sstream>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

std::string hashFile(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for hashing.");
    }

    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    char buffer[8192];
    while (file.read(buffer, sizeof(buffer))) {
        SHA256_Update(&sha256, buffer, file.gcount());
    }
    SHA256_Update(&sha256, buffer, file.gcount());

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }

    return ss.str();
}

std::string storeBlob(const std::string& filePath) {
    std::string hash = hashFile(filePath);
    std::string blobPath = "data/blobs/" + hash;

    // Create blobs directory if it doesn't exist
    fs::create_directories("data/blobs");

    if (!fs::exists(blobPath)) {
        fs::copy_file(filePath, blobPath);
    }
    return hash;
}
