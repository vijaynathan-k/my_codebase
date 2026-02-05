cmake_minimum_required(VERSION 3.10) #Ensures the user has at least CMake version 3.10 installed. If they have an older version, CMake will stop and throw an error.
project(using_nlohmann_json_third_party_lib) #Sets the name of the project. This also initializes several internal variables like PROJECT_NAME.

#${CMAKE_CURRENT_SOURCE_DIR} is the folder where this CMakeLists.txt lives.
set(JSON_LIB_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/../../third-party/json")#Creates a variable JSON_LIB_SOURCE pointing to the directory containing the JSON library's source code/build logic. 
set(JSON_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../third-party/json/single_include")#Creates a variable JSON_PATH pointing specifically to where the header files (.hpp) are located.

#[[
The first part(arg1 of add_subdirectory): Tells CMake to look into the JSON library folder and run the CMakeLists.txt found there.
The second part(arg2 of add_subdirectory): Because the library is outside your current project folder, you must explicitly tell CMake where to put the build files for it (in this case, a folder named json_build inside your build directory).
]]
add_subdirectory(${JSON_LIB_SOURCE} "${CMAKE_CURRENT_BINARY_DIR}/json_build")


#Tells CMake to compile main.cpp and link it into an executable file named using_nlohmann_json_app
add_executable(using_nlohmann_json_app main.cpp)

#[[
This is the most important part. It links your app to the nlohmann_json library target.
The :: notation indicates it is using an "alias target" defined by the library, which automatically handles all the necessary compiler flags for you.
]]
target_include_directories(using_nlohmann_json_app PRIVATE ${JSON_PATH})
target_link_libraries(using_nlohmann_json_app PRIVATE nlohmann_json::nlohmann_json)