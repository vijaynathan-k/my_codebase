=============classes==================== 
* Here Dog class derives from Pet class
* They show inheritance.
* But the lack of virtual functions make them non-polymorphic; i.e. base class object or pointer is not automatically deduced to derived class.

=============pybind module==================== 
We need to define both base and derived classes in the Pybind module
* In case of derived class, we also need to mention its base class
    * py::class_<Dog, Pet>(m, "dog")
* In this code, PetStore is defined as a module-level function inside the inheritance_and_auto_downcasting module.
    * Because you called m.def (where m is the module object) instead of chaining it to one of the .def calls of the classes, it sits at the top level of the module namespace.
    * PYBIND11_MODULE(inheritance_and_auto_downcasting, m){
            py::class_<Pet>(m, "Pet")
                .def(py::init<const std::string &>())
                .def_readwrite("name",&Pet::name);

            py::class_<Dog, Pet>(m, "dog")
                .def(py::init<const std::string &>())
                .def("bark", &Dog::bark);

            m.def("PetStore", [](){return std::unique_ptr<Pet>(new Dog("Woolfy"));});
        }

=============python====================        
* Here the pet store creates object of dog but returns it as base pointer. Pybind11 doesn't automatically downcast it to dog, when checked the type is Pet.
  This happens because even though dog derives from Pet (i.e. inheritance) they are not polymorphic because of lack of virtual functions.
    * ps = iaad.PetStore()
      print(type(ps))
