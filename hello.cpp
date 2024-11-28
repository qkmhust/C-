#include <iostream>
#include <vector>

int main() {
    auto x = 10; // x 的类型是 int
    auto y = 3.14; // y 的类型是 double
    auto z = "Hello, World!"; // z 的类型是 const char*

    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it = vec.begin(); // it 的类型是 std::vector<int>::iterator

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "z: " << z << std::endl;

    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}