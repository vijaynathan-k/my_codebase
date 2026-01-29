cmake_minimum_required(VERSION 3.10)
project(using_nlohmann_json_third_party_lib)

# add_subdirectory(../../third-party/json)
    # target_link_libraries(my_app PRIVATE nlohmann_json::nlohmann_json)
# 
set(JSON_LIB_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/../../third-party/json")
set(JSON_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../third-party/json/single_include")


add_subdirectory(${JSON_LIB_SOURCE} "${CMAKE_CURRENT_BINARY_DIR}/json_build")


# Create an executable named 'my_app' from 'hello_world.cpp'
add_executable(using_nlohmann_json_app main.cpp)

target_include_directories(using_nlohmann_json_app PRIVATE ${JSON_PATH})
target_link_libraries(using_nlohmann_json_app PRIVATE nlohmann_json::nlohmann_json)