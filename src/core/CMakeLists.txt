add_library(core_module
    apimongo.cpp
)

target_include_directories(core_module PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(core_module PUBLIC
    Qt6::Core
    mongo::mongocxx_shared
    mongo::bsoncxx_shared
)
