# My Version Control System (MVCS)

My Version Control System (MVCS) is a simple, custom version control system implemented in C++. It includes basic remote repository management commands, such as adding, removing, and listing remotes.

## Features

- **Remote Repository Management**:
  - Add a remote repository with `remote add <name> <url>`
  - Remove a remote repository with `remote remove <name>`
  - List all remote repositories with `remote list`
  
## Getting Started

### Prerequisites

- C++ compiler (e.g., GCC, MSVC)
- CMake (to build the project)
- OpenSSL (for hashing functionality)

### Installation

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/myvc.git
   cd myvc
   ```

2. **Build The Project**:
   - Using CMake
     ```bash
     mkdir build
     cd build
     cmake ..
     make
     ```
     
   - For Windows with Visual Studio:
     ```bash
     mkdir build
     cd build
     cmake ..
     cmake --build .
     ```

3. **Run the Application**:
   ```bash
   ./myvc
   ```
   
## Usage
After running the myvc executable, you can interact with the CLI for remote repository management. Below are some example commands:

### Commands:
- **Add a Remote**:
  ```bash
  remote add <name> <url>
  ```
- Example:
  ```bash
  remote add origin https://github.com/user/repo.git
  ```
- **Remove a Remote**:
  ```bash
  remote remove <name>
  ```
- Example:
  ```bash
  remote remove origin
  ```
- **List Remotes**:
  ```bash
  remote list
  ```
- **Help**:
  ```bash
  help
  ```
- **Exit**:
  ```bash
  exit
  ```

## Project Structure:

```bash
myvc/
├── include/           # Header files
│   └── remote.h       # Remote management declarations
├── src/               # Source files
│   ├── main.cpp       # Main entry point for the CLI
│   ├── remote.cpp     # Remote management implementations
│   └── file_storage.cpp # File storage and hashing functions
├── CMakeLists.txt     # CMake build configuration
└── README.md          # This readme file
```
