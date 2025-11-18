cmake_minimum_required(VERSION 3.16)
project(PersonalDevControl VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt e MongoDB
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)
find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)

# Automação Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Subdiretórios dos módulos
add_subdirectory(src/core)
add_subdirectory(src/models)
add_subdirectory(src/ui)
# add_subdirectory(src/controllers)

# Executável principal
qt_add_executable(PersonalDevControl
    src/main.cpp
    resources/personaldevcontrol.qrc
)

target_link_libraries(ui_module PUBLIC nlohmann_json::nlohmann_json)
# Linkagem dos módulos
target_link_libraries(PersonalDevControl PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Gui
    
    core_module
    models_module
    ui_module
#     controllers_module
)

# Headers públicos
target_include_directories(PersonalDevControl PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR}  # For generated ui_*.h from uic
)

# Output do binário
set_target_properties(PersonalDevControl PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
