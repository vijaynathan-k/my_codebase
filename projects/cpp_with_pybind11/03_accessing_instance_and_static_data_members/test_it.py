import class_and_struct as cas

p = cas.Pet("Molly")
p.name = "setting the instance variable"
print(p.name)

print("accessing the const variable ", p.m_initial_name)
