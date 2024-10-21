#ifndef FILE_STORAGE_H
#define FILE_STORAGE_H

#include <string>

// Function to hash the content of a file
std::string hashFile(const std::string& filePath);

// Function to store a file blob (contents) in the repository
std::string storeBlob(const std::string& filePath);

#endif // FILE_STORAGE_H
