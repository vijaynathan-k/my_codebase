#include <string>
#include "pybind11/pybind11.h"
#include <iostream>

namespace py = pybind11;

class dummy{
    public:
        dummy() = default;
        ~dummy() = default;
    
        void print_something()
        {
            std::cout << "print something!" << std::endl;
        }
};

struct Pet {
    Pet(const std::string &name) : name(name) { }
    void setName(const std::string &name_) { name = name_; }
    const std::string &getName() const { return name; }

    std::string name;
};

class class_with_value_arg{
public:
    explicit class_with_value_arg(Pet p)
    : m_pet{p}
    {        
    }
    void print_pet_name()
    {
        std::cout << m_pet.getName() << std::endl;
    }
private:
    Pet m_pet;
};

class class_with_reference_arg{
public:
    class_with_reference_arg(Pet& p)
        : m_pet(p)
    {
    }

    void print_pet_name()
    {
        std::cout << "class_with_reference_arg, pet name : " << m_pet.getName() << std::endl;
    }
private:
    Pet& m_pet;
};

class class_with_raw_ptr{
    public:
        class_with_raw_ptr(Pet* p)
            : m_pet{p}
        {            
        }

        void print_pet_name()
        {
            if(!m_pet)
                std::cout << "class_with_raw_ptr, m_pet is null!" << std::endl;

            std::cout << "class_with_raw_ptr, pet name : " << m_pet->getName() << std::endl;
        }
private:
    Pet* m_pet;
};

/*
py::class_ creates bindings for a C++ class or struct-style data structure. 
init() is a convenience function that takes the types of a constructor’s parameters as template arguments 
and wraps the corresponding constructor
*/
PYBIND11_MODULE(class_and_struct, m){
    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &>())
        .def("setName", &Pet::setName)
        .def("getName", &Pet::getName);

    py::class_<dummy>(m, "dummy")
        .def(py::init()) //default constructor
        .def("print_something", &dummy::print_something);
    
    py::class_<class_with_value_arg>(m, "class_with_value_arg")
        .def(py::init<Pet>())
        .def("print_pet_name", &class_with_value_arg::print_pet_name);

    py::class_<class_with_reference_arg>(m, "class_with_reference_arg")
        .def(py::init<Pet&>())
        .def("print_pet_name", &class_with_reference_arg::print_pet_name);
    
    py::class_<class_with_raw_ptr>(m, "class_with_raw_ptr")
        .def(py::init<Pet *>())
        .def("print_pet_name", &class_with_raw_ptr::print_pet_name);
}