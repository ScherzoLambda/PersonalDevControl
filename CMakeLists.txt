cmake_minimum_required(VERSION 3.16.0)

project(PersonalDevControl VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#
# Garante que o CMake procure pacotes APENAS em /usr/local
#
set(CMAKE_PREFIX_PATH "/usr/local")
set(CMAKE_LIBRARY_PATH "/usr/local/lib")
set(CMAKE_INCLUDE_PATH "/usr/local/include")

#
# Encontrar Qt e MongoDB C++ Drivers
#
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)
find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)

#
# Fontes
#
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

set(UI_FILES
        src/ui/personaldevcontrol.ui
        src/ui/loginMongo.ui
)

qt_add_executable(PersonalDevControl
        ${SOURCES}
        ${HEADERS}
        ${UI_FILES}
        resources/personaldevcontrol.qrc
)

set_target_properties(PersonalDevControl PROPERTIES
        AUTORCC ON
        AUTOUIC ON
        AUTOMOC ON
)

#
# Linkagem somente com as bibliotecas do /usr/local/lib
#
target_link_libraries(PersonalDevControl PRIVATE
        Qt6::Core
        Qt6::Widgets
        Qt6::Gui
        mongo::mongocxx_shared
        mongo::bsoncxx_shared
)

#
# Includes
#
target_include_directories(PersonalDevControl PRIVATE
        .
        src
        src/ui
        src/core
        src/models
        ${CMAKE_CURRENT_BINARY_DIR}
        /usr/local/include
)

#
# Output do executável
#
set_target_properties(PersonalDevControl PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
