#ifndef REMOTE_H
#define REMOTE_H

#include <string>
#include <vector>

class Remote {
public:
    Remote(const std::string &name, const std::string &url);
    std::string getName() const;
    std::string getUrl() const;

private:
    std::string name;
    std::string url;
};

class RemoteManager {
public:
    void addRemote(const std::string &name, const std::string &url);
    void removeRemote(const std::string &name);
    void listRemotes() const;
    void push(const std::string &branchName);
    void pull(const std::string &branchName);

private:
    std::vector<Remote> remotes;
};

#endif // REMOTE_H
