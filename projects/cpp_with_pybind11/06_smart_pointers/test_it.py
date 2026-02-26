import smart_pointers as sp

print("\n\n====================ACCESSING the print message from unique ptr======================")
unique_ptr = sp.create_some_class_as_unique_ptr()
unique_ptr.print();

print("\n\n====================ACCESSING the print message from shared ptr======================")
shared_ptr = sp.create_some_class_as_shared_ptr()
shared_ptr.print();