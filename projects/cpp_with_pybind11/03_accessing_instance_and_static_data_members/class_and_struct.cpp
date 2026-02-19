#include <string>
#include "pybind11/pybind11.h"
#include <iostream>

namespace py = pybind11;

struct Pet {
    Pet(const std::string &name) 
        :   name(name),
            m_initial_name {"CONST VALUE"}
    {
    }
    
    void setName(const std::string &name_) { name = name_; }
    const std::string &getName() const { return name; }

    std::string name;
    const std::string m_initial_name;
    inline static std::string STATIC_NAME {"static string"};
};

/*
py::class_ creates bindings for a C++ class or struct-style data structure. 
init() is a convenience function that takes the types of a constructor’s parameters as template arguments 
and wraps the corresponding constructor
*/
PYBIND11_MODULE(class_and_struct, m){
    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &>())
        .def_readwrite("name",&Pet::name)
        .def_readonly("m_initial_name", &Pet::m_initial_name);
}