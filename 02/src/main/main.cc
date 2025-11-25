#include <iostream>
#include "greeter.h" 

int main() {
    std::cout << simple_app::GetGreet("Bazel C++") << std::endl;
    return 0;
}