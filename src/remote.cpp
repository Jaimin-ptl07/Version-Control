#include "D:\myvc\include\remote.h"
#include <iostream>

Remote::Remote(const std::string &name, const std::string &url) : name(name), url(url) {}

std::string Remote::getName() const {
    return name;
}

std::string Remote::getUrl() const {
    return url;
}

void RemoteManager::addRemote(const std::string &name, const std::string &url) {
    remotes.emplace_back(name, url);
    std::cout << "Added remote: " << name << " (" << url << ")\n";
}

void RemoteManager::removeRemote(const std::string &name) {
    remotes.erase(std::remove_if(remotes.begin(), remotes.end(),
                  [&name](const Remote &remote) { return remote.getName() == name; }), remotes.end());
    std::cout << "Removed remote: " << name << "\n";
}

void RemoteManager::listRemotes() const {
    std::cout << "Configured remotes:\n";
    for (const auto &remote : remotes) {
        std::cout << remote.getName() << " -> " << remote.getUrl() << "\n";
    }
}

void RemoteManager::push(const std::string &branchName) {
    // Implement the logic to push changes to the remote repository.
}

void RemoteManager::pull(const std::string &branchName) {
    // Implement the logic to pull changes from the remote repository.
}
