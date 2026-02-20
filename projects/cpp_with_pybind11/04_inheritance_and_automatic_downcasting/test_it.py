import inheritance_and_auto_downcasting as iaad

p = iaad.dog("Molly")
p.name = "setting the instance variable"
print(p.name)

dog = iaad.dog("Woolfy")
print(dog.bark())

# Here the pet store creates object of dog but returns it as base pointer. Pybind11 doesn't automatically downcast it to dog, when checked the type is Pet.
# This happens because even though dog derives from Pet (i.e. inheritance) they are not polymorphic because of lack of virtual functions.
ps = iaad.PetStore()
print(type(ps))