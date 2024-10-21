cmake_minimum_required(VERSION 3.10)

project(myvc)


# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenSSL
find_package(OpenSSL REQUIRED)


set(OPENSSL_ROOT_DIR "C:/Users/JAIMIN/vcpkg/packages/openssl_x64-windows")
set(OPENSSL_INCLUDE_DIR "C:/Users/JAIMIN/vcpkg/packages/openssl_x64-windows/include")
set(OPENSSL_CRYPTO_LIBRARY "C:/Users/JAIMIN/vcpkg/packages/openssl_x64-windows/lib/libcrypto.lib")
set(OPENSSL_SSL_LIBRARY "C:/Users/JAIMIN/vcpkg/packages/openssl_x64-windows/lib/libssl.lib")

# Add the executable target
add_executable(myvc src/main.cpp src/file_storage.cpp src/remote.cpp)

# Include OpenSSL directories
target_include_directories(myvc PRIVATE ${OPENSSL_INCLUDE_DIR})

# Link OpenSSL libraries
target_link_libraries(myvc PRIVATE ${OPENSSL_SSL_LIBRARY} ${OPENSSL_CRYPTO_LIBRARY})

# Optional: Set include directories if needed
include_directories(include)
