cmake_minimum_required(VERSION 3.14)
project(PythonCppInterop)

# 1. Set the path to your local pybind11 directory
# Replace "../external/pybind11" with your actual path
set(PYBIND11_LIB_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/../../../third-party/pybind11")
set(PYBIND11_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../third-party/pybind11/include")

# 2. Add the directory to the build
# This makes the 'pybind11_add_module' command available
add_subdirectory(${PYBIND11_LIB_SOURCE} "${CMAKE_CURRENT_BINARY_DIR}/pybind11_build")

# 3. Create the Python module
# 'smart_pointers' is the module name, 'smart_pointers.cpp' is your source
pybind11_add_module(smart_pointers smart_pointers.cpp)

target_include_directories(smart_pointers PRIVATE ${PYBIND11_LIB_PATH})

# Copies test.py from source folder to build folder
configure_file(test_it.py ${CMAKE_CURRENT_BINARY_DIR}/test_it.py COPYONLY)