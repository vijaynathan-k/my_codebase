import class_and_struct as cas

p = cas.Pet("Molly")
print(p.getName())

dmy = cas.dummy()
dmy.print_something()

obj = cas.class_with_value_arg(p)
obj.print_pet_name()

ref = cas.class_with_reference_arg(p)
ref.print_pet_name()

obj = cas.class_with_raw_ptr(p)
obj.print_pet_name()