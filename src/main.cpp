#include <iostream>
#include <sstream>  // Include sstream for istringstream
#include <string>
#include "D:\myvc\include\remote.h"  // Include the remote header file

void displayHelp() {
    std::cout << "Available commands:\n";
    std::cout << "  remote add <name> <url>  - Add a remote repository\n";
    std::cout << "  remote remove <name>      - Remove a remote repository\n";
    std::cout << "  remote list               - List all remotes\n";
    // Add more commands as needed
}

int main() {
    RemoteManager remoteManager;
    std::string command;

    std::cout << "Welcome to My Version Control System (MVCS)\n";
    std::cout << "Type 'help' for a list of commands.\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);

        // Split command into parts
        std::istringstream iss(command);
        std::string cmd;
        iss >> cmd;

        if (cmd == "help") {
            displayHelp();
        } 
        else if (cmd == "remote") {
            std::string subCommand;
            iss >> subCommand;

            if (subCommand == "add") {
                std::string name, url;
                iss >> name >> url;  // Read name and URL from the input stream
                remoteManager.addRemote(name, url);
            } 
            else if (subCommand == "remove") {
                std::string name;
                iss >> name;  // Read name from the input stream
                remoteManager.removeRemote(name);
            } 
            else if (subCommand == "list") {
                remoteManager.listRemotes();
            } 
            else {
                std::cout << "Unknown remote command: " << subCommand << "\n";
            }
        } 
        else if (command == "exit") {
            break;  // Exit the program
        } 
        else {
            std::cout << "Unknown command. Type 'help' for a list of commands.\n";
        }
    }

    return 0;
}
