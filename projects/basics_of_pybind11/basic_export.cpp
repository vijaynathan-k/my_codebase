#include <pybind11/pybind11.h>

// 1. Define the actual C++ logic
int add(int i, int j) {
    return i + j;
}

// 2. Create the Python module
// "fast_math" is the name you will use in Python: 'import fast_math'
PYBIND11_MODULE(fast_math, m) {
    m.doc() = "A simple C++ math plugin for Python"; // optional docstring
    
    // Expose the 'add' function to Python
    m.def("add", &add, "A function that adds two integers");
}
