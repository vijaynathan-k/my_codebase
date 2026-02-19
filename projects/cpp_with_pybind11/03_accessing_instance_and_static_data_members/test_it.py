import class_and_struct as cas

p = cas.Pet("Molly")
p.name = "setting the instance variable"
print(p.name)

print("accessing the const variable ", p.m_initial_name)
print("accessing the static variable ", p.STATIC_NAME)
print("accessing the static_const_data_member ", p.static_const_data_member)