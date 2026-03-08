#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int main()
{
    // 定义一个lambda表达式，输出"Hello, World!"
    auto printHello = []{ cout << "Hello, World!" << endl; };
    printHello(); // 调用lambda表达式

    // 定义一个lambda表达式，计算两个整数的和
    auto add = [](int a, int b) -> int { return a + b; };
    cout << add(3, 4) << endl; // 输出3 + 4的结果

    int factor = 2;
    // 定义一个lambda表达式，计算一个整数与factor的乘积
    auto multiply = [factor](int a) -> int { return a * factor; };
    cout << multiply(5) << endl; // 输出5 * factor的结果

    int count = 0;
    // 定义一个lambda表达式，增加count的值
    auto increment = [&count]() { count++; };
    increment(); // 调用lambda表达式
    cout << count << endl; // 输出count的值

    vector<int> vec = {4, 2, 3, 1, 5};
    // 使用lambda表达式对向量进行升序排序
    sort(vec.begin(), vec.end(), [](int a, int b) { return a < b; });
    for (auto v : vec) cout << v << " "; // 输出排序后的向量
    cout << endl;

    vec = {1, 2, 3, 4, 5};
    // 使用lambda表达式移除向量中的偶数
    vec.erase(remove_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }), vec.end());
    for (auto v : vec) cout << v << " "; // 输出移除偶数后的向量
    cout << endl;

    int a = 1, b = 2;
    // 定义一个lambda表达式，返回a和b的和
    auto sum = [=]() { return a + b; };
    cout << sum() << endl; // 输出a + b的结果

    a = 1, b = 2;
    // 定义一个lambda表达式，增加a和b的值
    auto incrementAll = [&]() { a++; b++; };
    incrementAll(); // 调用lambda表达式
    cout << a << " " << b << endl; // 输出增加后的a和b的值

    // 定义一个lambda表达式，计算阶乘
    function<int(int)> factorial = [&](int n) { return n <= 1 ? 1 : n * factorial(n - 1); };
    cout << factorial(5) << endl; // 输出5的阶乘

    // 定义一个泛型lambda表达式，计算两个参数的和
    auto genericAdd = [](auto a, auto b) { return a + b; };
    cout << genericAdd(1, 2) << endl; // 输出1 + 2的结果
    cout << genericAdd(1.5, 2.5) << endl; // 输出1.5 + 2.5的结果

    return 0; // 返回0，表示程序成功结束
}