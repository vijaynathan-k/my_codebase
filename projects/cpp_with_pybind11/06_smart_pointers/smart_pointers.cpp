#include <string>
#include "pybind11/pybind11.h"
#include <iostream>
#include <memory>

namespace py = pybind11;

struct some_class {
    some_class() = default;
    ~some_class() = default;

    void print(){
        std::cout << "Print message form some_class!!!" << std::endl;
    }
};

std::unique_ptr<some_class> create_some_class_as_unique_ptr()
{
    return std::make_unique<some_class>();
}

std::shared_ptr<some_class> create_some_class_as_shared_ptr()
{
    return std::make_shared<some_class>();
}

/*
py::class_ creates bindings for a C++ class or struct-style data structure. 
init() is a convenience function that takes the types of a constructor’s parameters as template arguments 
and wraps the corresponding constructor

For unique_ptr when using py_class_
* py::class_<some_class>(m, "some_class")
** Here only class name 'some_class' is given to py_class_; as pybind11 default to unique ptr

For shared_ptr when using py_class_
* py::class_<some_class, std::shared_ptr<some_class>>(m, "some_class")
** Here class name 'some_class' is given to py_class_;
** And we have to explicitly mention the type is shared_ptr to py_class

Now you notice that the py_class syntax is different for unique and shared ptr.
Now what if you have to use both. This problem is solved by passing py::smart_holder to py_class
py::class_<some_class, py::smart_holder>(m, "some_class")
** Below example demos this case
*/

PYBIND11_MODULE(smart_pointers, m){
    py::class_<some_class, py::smart_holder>(m, "some_class")
        .def(py::init<>())
        .def("print", &some_class::print);
    
    m.def("create_some_class_as_unique_ptr", &create_some_class_as_unique_ptr);
    m.def("create_some_class_as_shared_ptr", &create_some_class_as_unique_ptr);
}

