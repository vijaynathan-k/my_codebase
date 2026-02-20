=============classes==================== 
* we have Pet::set overload with different arg types
* Pet::get_age overload with const and non-const

=============pybind module==================== 
* Normally we use .def("set",&Pet::set) to bind the set method
    * But here it will be same for both overload of set
    * To disambiguate this we can use overload_cast
    * overload_cast takes the arg type
        * .def("set",py::overload_cast<int>(&Pet::set))
        * .def("set", py::overload_cast<const std::string &>(&Pet::set))
    * In case the arg type is not there like in case of get_age()
        * overload_cast will have nothing inside the angular brackets
        * .def("get_age_non_const",py::overload_cast<>(&Pet::get_age))
    * In case overload is by constness, we use py::const_
        * .def("get_age_const",py::overload_cast<>(&Pet::get_age, py::const_))
        * also the tags should be different which will be called from python, because there are arg types based on which 
          it can be distinguished
        * .def("get_age_non_const",py::overload_cast<>(&Pet::get_age))
        * .def("get_age_const",py::overload_cast<>(&Pet::get_age, py::const_))

=============python====================        
* Based on the arg type for set, the correct overload method is called
    * p.set("woolfy") // set(string)
    * p.set(10) // set(int)
* In case of get_age, there are no args, so differect tags are used to call the get_age overload methods
    * p.get_age_const() // calls get_age() const
    * p.get_age_non_const() // call get_age() non const
