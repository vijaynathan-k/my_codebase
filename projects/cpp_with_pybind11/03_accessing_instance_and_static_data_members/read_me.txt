def_readwrite - access instance variables
def_readonly - access const variables
def_readwrite_static - access non const static variables
def_readonly_static - access const static variables

In cpp file while binding to the PYBIND11_MODULE, for static variables also you need to pass the 
pointer, as the pybind11 requires the address at which "STATIC_NAME" variable is stored.
    .def_readwrite_static("STATIC_NAME", &Pet::STATIC_NAME)

If we don't give the &, even though it will not compile because the def_readwrite_static method needs access
pointer, just for understanding purpose assume it works, then if we just give Pet::STATIC_NAME, this means the 
current value of variable STATIC_NAME is sent to python, but we dont want that, we want the updated value
whenever its called from python. so when you give &, it will go get the value from that memory location every
time its requested.

def_readwrite_static is implcitly converted into getter and setter function w.r.t the static variable


=================================
Even in python, we will access the static variable using the instance of the class itself

import class_and_struct as cas
p = cas.Pet("Molly")
print("accessing the static_const_data_member ", p.static_const_data_member)