cmake_minimum_required(VERSION 3.16.0)

project(PersonalDevControl VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt6 packages
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)

# Find libcurl
find_package(PkgConfig REQUIRED)
pkg_check_modules(CURL REQUIRED libcurl)

# Define source files
set(SOURCES
    src/main.cpp
    src/ui/personaldevcontrol.cpp
    src/ui/loginmongo.cpp
    src/core/apimongo.cpp
    src/models/modelTask.cpp
)

set(HEADERS
    src/ui/personaldevcontrol.h
    src/ui/loginmongo.h
    src/core/apimongo.h
    src/models/modelTask.h
    ui_loginMongo.h
)

# Process UI files manually since qt6_add_uic might not be available in older versions
set(UI_FILES
    src/ui/personaldevcontrol.ui
    src/ui/loginMongo.ui
)

# Create executable
qt_add_executable(PersonalDevControl ${SOURCES} ${HEADERS} ${UI_FILES} resources/personaldevcontrol.qrc)

# Set Qt properties
set_target_properties(PersonalDevControl PROPERTIES
    AUTORCC ON
    AUTOUIC ON
    AUTOMOC ON
)

# Link libraries
target_link_libraries(PersonalDevControl PRIVATE
    Qt6::Core 
    Qt6::Widgets 
    Qt6::Gui
    ${CURL_LIBRARIES}
)

# Include directories
target_include_directories(PersonalDevControl PRIVATE
    .                        # Root directory for ui_loginMongo.h
    src
    src/ui
    src/core
    src/models
    ${CMAKE_CURRENT_BINARY_DIR}  # For generated UI headers
    ${CURL_INCLUDE_DIRS}
)

# Compiler flags for libcurl
target_compile_options(PersonalDevControl PRIVATE ${CURL_CFLAGS_OTHER})

# Set output directory
set_target_properties(PersonalDevControl PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)