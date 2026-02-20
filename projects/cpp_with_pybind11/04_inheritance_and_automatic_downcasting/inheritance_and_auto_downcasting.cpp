#include <string>
#include "pybind11/pybind11.h"
#include <iostream>

namespace py = pybind11;

// Non-plymorphic;no virtual function
struct Pet {
    Pet(const std::string &name) 
        : name(name) 
    {
    }
    std::string name;
};

struct Dog : Pet {
    Dog(const std::string &name) : Pet(name) { }
    std::string bark() const { return "woof!"; }
};

// Polymorphic
struct PolymorphicPet {
    virtual ~PolymorphicPet() = default;
};

struct PolymorphicDog : PolymorphicPet {
    std::string bark() const { return "woof!"; }
};

/*
py::class_ creates bindings for a C++ class or struct-style data structure. 
init() is a convenience function that takes the types of a constructor’s parameters as template arguments 
and wraps the corresponding constructor
*/

PYBIND11_MODULE(inheritance_and_auto_downcasting, m){
    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &>())
        .def_readwrite("name",&Pet::name);

    py::class_<Dog, Pet>(m, "dog")
        .def(py::init<const std::string &>())
        .def("bark", &Dog::bark);

    py::class_<PolymorphicPet>(m, "PolymorphicPet");

    py::class_<PolymorphicDog, PolymorphicPet>(m, "PolymorphicDog")
        .def(py::init())
        .def("bark", &PolymorphicDog::bark);


    m.def("PetStore", [](){return std::unique_ptr<Pet>(new Dog("Woolfy"));});
    m.def("polymorphic_PetStore", [](){return std::unique_ptr<PolymorphicPet>(new PolymorphicDog());});
}

