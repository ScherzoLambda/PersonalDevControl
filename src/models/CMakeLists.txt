add_library(models_module
    modelTask.cpp
    modelUser.cpp
)

target_include_directories(models_module PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(models_module PUBLIC
    Qt6::Core
)
