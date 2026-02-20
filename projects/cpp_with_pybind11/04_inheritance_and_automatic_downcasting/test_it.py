import inheritance_and_auto_downcasting as iaad

print("\n\n====================ACCESSING THE DERIVED CLASS OBJECT DIRECTLY!!!======================")
p = iaad.dog("Molly")
p.name = "setting the instance variable"
print(p.name)

dog = iaad.dog("Woolfy")
print(dog.bark())

# Here the pet store creates object of dog but returns it as base pointer. Pybind11 doesn't automatically downcast it to dog, when checked the type is Pet.
# This happens because even though dog derives from Pet (i.e. inheritance) they are not polymorphic because of lack of virtual functions.


try:
    print("\n\n====================ERROR : ACCESSING THE DERIVED CLASS METHOD USING BASE OBJECT; NON POLYMORPHIC!!!======================")
    ps = iaad.PetStore()
    print("Expected type is dog but was ", type(ps))

    print("\nTrying to access derived object from base object : ")
    ps.bark() #commented as this will throw error
except Exception as e:
    # Code to run if any exception occurs
    print(f"An exception occurred: {e}")

# ------------------------
print("\n\n====================SUCCESS : ACCESSING THE DERIVED CLASS METHOD USING BASE OBJECT; POLYMORPHIC!!!======================")
pps = iaad.polymorphic_PetStore()
print("Expected type is dog but was ", type(pps))

print("\nTrying to access derived object from base object : ")
print(pps.bark())