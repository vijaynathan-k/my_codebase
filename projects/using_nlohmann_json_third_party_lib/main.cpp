#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
int main()
{
    
    std::cout << "Hello from using_nlohmann_json_third_party_lib 1" << std::endl;
      // 1. Create a JSON object
    json data;
    data["project"] = "using_nlohmann_json";
    data["status"] = "compiling";
    data["pi"] = 3.141;

    // 2. Print formatted JSON (indent of 4 spaces)
    std::cout << data.dump(4) << std::endl;

    // 3. Access data
    std::string project_name = data["project"];
    std::cout << "Successfully using: " << project_name << std::endl;

    return 0;
}