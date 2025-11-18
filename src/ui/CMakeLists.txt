add_library(ui_module
    loginmongo.cpp
    personaldevcontrol.cpp
    ${PROJECT_SOURCE_DIR}/include/ui/loginmongo.hpp
    ${PROJECT_SOURCE_DIR}/include/ui/personaldevcontrol.hpp
    LoginTasks.ui
    personaldevcontrol.ui
)

target_include_directories(ui_module PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR}  # Onde ui_*.h são gerados
)

target_link_libraries(ui_module PUBLIC
    Qt6::Widgets
    Qt6::Gui
    core_module
    models_module
)

set_target_properties(ui_module PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)
