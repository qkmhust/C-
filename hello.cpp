#include <iostream>
#include <vector>

int main() {
    auto x = 10; 
    auto y = 3.14; 
    auto z = "Hello, World!"; 

    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it = vec.begin(); 

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "z: " << z << std::endl;

    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}