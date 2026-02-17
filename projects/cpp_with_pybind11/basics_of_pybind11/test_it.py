import fast_math

result_add = fast_math.add(10, 5)
result_substract = fast_math.substract(10,5)
result_multiply_with_default_args = fast_math.multiply()
result_multiply_with_custom_args = fast_math.multiply(5,10)

print(f"Result from C++ Add: {result_add}")
print(f"Type of result_add: {type(result_add)}")
print(f"Result from C++ Substract: {result_substract}")
print(f"Result with default args from C++ multiply: {result_multiply_with_default_args}")
print(f"Result with custom args from C++ multiply: {result_multiply_with_custom_args}")


print("exporting int : ", fast_math.int_value)

print("exporting complex obj like string : ", fast_math.string_obj)