#include <iostream>
#include <vector>
#include <ranges>
int main(){
    std::vector<int> v{1,2,3,4,5};
    auto even = v | std::views::filter([](int x){ return x % 2 == 0; });
    for (int x : even) std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}
