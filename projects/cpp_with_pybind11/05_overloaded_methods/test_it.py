import overloaded_methods as om

print("\n\n====================ACCESSING the overloaded method set for name and age======================")
p = om.Pet("Molly", 5)
p.set("woolfy")
p.set(10)

print(p.name)
print("\n\n====================ACCESSING the overloaded method get_age const======================")
print(p.get_age_const())
print("\n\n====================ACCESSING the overloaded method get_age; ++age======================")
print(p.get_age_non_const())
