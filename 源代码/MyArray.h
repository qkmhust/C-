#include <iostream>
#include <memory>


class MyArray final{
    friend std::ostream& operator<<(std::ostream& os, const MyArray& arr);
public: 
    MyArray(int size);
    ~MyArray();
    MyArray(const MyArray& other);
    MyArray(MyArray&& other) noexcept;
    MyArray& operator=(const MyArray& other);
    MyArray& operator=(MyArray&& other) noexcept;
    int& operator[](int index);
    const int& operator[](int index) const;
private:
    size_t m_size{0};
    std::unique_ptr<int[]> m_ptr;
};