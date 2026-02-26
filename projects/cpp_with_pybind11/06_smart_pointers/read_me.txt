Smart pointers & py::class_  

* In pybind11, py::class_ uses a holder type to manage the lifetime of C++ objects exposed to Python. 
* This mechanism ensures that the C++ object isn't destroyed while Python still holds a reference to it. 

 

The Role of py::class_ 
* py::class_ is the primary template used to create Python bindings for C++ classes. By default, it uses std::unique_ptr<T> as the internal "holder". 
* Default Behavior: When Python's reference count for an object drops to zero, the unique_ptr deallocates the C++ object. 
* Limitation: You can only associate one holder type per class. 


In pybind11, "holders" manage the lifecycle of C++ objects within Python. While std::unique_ptr is the default, choosing the right holder is critical for memory safety and interoperability. 

1. std::unique_ptr (The Default) 

Use this when Python has exclusive ownership of the object. When the Python object is garbage collected, the C++ object is deleted.  
pybind11 documentation

pybind11 documentation +3 
    Best for: Factory functions where C++ "hands off" the object to Python. 
    Limitation: You cannot pass a unique_ptr from Python back to a C++ function as an argument in "classic" pybind11.  


// Binding (Holder is std::unique_ptr by default) 
py::class_<Data>(m, "Data") 
    .def(py::init<>()); 

// C++ Function 
std::unique_ptr<Data> create_data() { 
    return std::make_unique<Data>();  
} 

// Exposure 
m.def("create_data", &create_data); 

 

2. std::shared_ptr 
Use this when multiple owners (both C++ and Python) need to keep the object alive.  
    Best for: Long-lived objects stored in C++ containers that are also manipulated in Python. 
    Critical Rule: You must explicitly specify std::shared_ptr as the second template argument in py::class_. 

// Binding (Explicitly set shared_ptr as holder) 
py::class_<Data, std::shared_ptr<Data>>(m, "Data") 
    .def(py::init<>()); 

// C++ Function 
std::shared_ptr<Data> get_shared_data(std::shared_ptr<Data> ptr) { 
    return ptr; // Safe: both sides share the same control block 
} 

3. py::smart_holder (The Modern Standard) 
The smart_holder branch (and upcoming pybind11 v3) solves the "one-holder" limitation. It allows a single class to interoperate with both unique_ptr and shared_ptr simultaneously.  
GitHub
    Best for: Complex APIs where some functions return unique_ptr and others return shared_ptr. 
    Key Advantage: It allows "disowning" an object—passing a Python-owned object back to C++ as a std::unique_ptr.  

// Binding (Using the flexible smart_holder) 
py::class_<Data, py::smart_holder>(m, "Data") 
    .def(py::init<>()); 

// Now BOTH of these work with the same class: 
m.def("func_a", [](std::unique_ptr<Data> p) { /* Python hands over ownership */ }); 
m.def("func_b", [](std::shared_ptr<Data> p) { /* Python shares ownership */ }); 