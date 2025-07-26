cmake_minimum_required(VERSION 3.10)
project(BankApplication)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add all source files (adjust as needed)
file(GLOB SOURCES
    "src/*.cpp"
    "ConsoleApplication.cpp"
)

# Add all headers (for IDE support)
file(GLOB HEADERS
    "include/*.h"
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    include/
    src/
)

# For Windows (uncomment if needed)
# if(WIN32)
#     target_link_libraries(${PROJECT_NAME} PRIVATE ws2_32)  # For Windows sockets if used
# endif()