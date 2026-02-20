#include <string>
#include "pybind11/pybind11.h"
#include <iostream>

namespace py = pybind11;

struct Pet {
    Pet(const std::string &name, int age) : name(name), age(age) { }

    //overload by arg type
    void set(int age_) { age = age_; }
    void set(const std::string &name_) { name = name_; }

    // overload by constness
    int get_age(){return ++age;}
    int get_age() const {return age;}

    std::string name;
    int age;
};

/*
py::class_ creates bindings for a C++ class or struct-style data structure. 
init() is a convenience function that takes the types of a constructor’s parameters as template arguments 
and wraps the corresponding constructor
*/

PYBIND11_MODULE(overloaded_methods, m){
    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &, int>())
        .def("set",py::overload_cast<int>(&Pet::set))
        .def("set", py::overload_cast<const std::string &>(&Pet::set))
        .def("get_age_non_const",py::overload_cast<>(&Pet::get_age))
        .def("get_age_const",py::overload_cast<>(&Pet::get_age, py::const_))
        .def_readwrite("name", &Pet::name)
        .def_readwrite("age", &Pet::age);
}

