#include <pybind11/pybind11.h>
namespace py = pybind11;

// 1. Define the actual C++ logic
int add(int i, int j) {
    return i + j;
}

int substract(int i, int j)
{
    return i - j;
}

int multiply_with_default_args(int i = 2, int j = 3)
{
    return i*j;
}

// 2. Create the Python module
// "fast_math" is the name you will use in Python: 'import fast_math'
PYBIND11_MODULE(fast_math, m) {
    m.doc() = "A simple C++ math plugin for Python"; // optional docstring
    
    // Expose the 'add' function to Python
    m.def("add", &add, "A function that adds two integers");
    m.def("substract", &substract, "A function to subtract two numbers", py::arg("i"), py::arg("j"));
    m.def("multiply", &multiply_with_default_args, "A function to multiply two numbers", py::arg("i")=2, py::arg("j")=3);

    /*
    To expose a value from C++, use the attr function to register it in a module as shown below.
    Built-in types and general objects (more on that later) are automatically converted when assigned as attributes,
    and can be explicitly converted using the function py::cast.
    */
    m.attr("int_value") = 42;

    // casting the string obj to py object; then putting it in obj_world_str
    py::object string_obj = py::cast("world");
    m.attr("string_obj") = string_obj;
}
