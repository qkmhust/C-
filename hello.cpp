#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int main()
{
    // ����һ��lambda���ʽ�����"Hello, World!"
    auto printHello = []{ cout << "Hello, World!" << endl; };
    printHello(); // ����lambda���ʽ

    // ����һ��lambda���ʽ���������������ĺ�
    auto add = [](int a, int b) -> int { return a + b; };
    cout << add(3, 4) << endl; // ���3 + 4�Ľ��

    int factor = 2;
    // ����һ��lambda���ʽ������һ��������factor�ĳ˻�
    auto multiply = [factor](int a) -> int { return a * factor; };
    cout << multiply(5) << endl; // ���5 * factor�Ľ��

    int count = 0;
    // ����һ��lambda���ʽ������count��ֵ
    auto increment = [&count]() { count++; };
    increment(); // ����lambda���ʽ
    cout << count << endl; // ���count��ֵ

    vector<int> vec = {4, 2, 3, 1, 5};
    // ʹ��lambda���ʽ������������������
    sort(vec.begin(), vec.end(), [](int a, int b) { return a < b; });
    for (auto v : vec) cout << v << " "; // �������������
    cout << endl;

    vec = {1, 2, 3, 4, 5};
    // ʹ��lambda���ʽ�Ƴ������е�ż��
    vec.erase(remove_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }), vec.end());
    for (auto v : vec) cout << v << " "; // ����Ƴ�ż���������
    cout << endl;

    int a = 1, b = 2;
    // ����һ��lambda���ʽ������a��b�ĺ�
    auto sum = [=]() { return a + b; };
    cout << sum() << endl; // ���a + b�Ľ��

    a = 1, b = 2;
    // ����һ��lambda���ʽ������a��b��ֵ
    auto incrementAll = [&]() { a++; b++; };
    incrementAll(); // ����lambda���ʽ
    cout << a << " " << b << endl; // ������Ӻ��a��b��ֵ

    // ����һ��lambda���ʽ������׳�
    function<int(int)> factorial = [&](int n) { return n <= 1 ? 1 : n * factorial(n - 1); };
    cout << factorial(5) << endl; // ���5�Ľ׳�

    // ����һ������lambda���ʽ���������������ĺ�
    auto genericAdd = [](auto a, auto b) { return a + b; };
    cout << genericAdd(1, 2) << endl; // ���1 + 2�Ľ��
    cout << genericAdd(1.5, 2.5) << endl; // ���1.5 + 2.5�Ľ��

    return 0; // ����0����ʾ����ɹ�����
}