# Move Semantics

## vec.emplace_back 和vec.push_back

`https://en.cppreference.com/w/cpp/container/vector/emplace_back`

emplace_back通常提供更好的性能，因为它直接在vector的内存中构造对象，避免了不必要的复制或移动操作。
否则widgets.push_back(Widget("example", 42));
这里首先构造了一个Widget对象，然后将其作为参数传递给push_back，这导致了至少一次对象的复制或移动操作（如果编译器没有优化的话）

## copy elision 复制省略

g++ -g -fno-elide-constructors -Wall -std=c++11 test.cpp -o test # 禁用copy elision

c++17标准保证了copy elision

## lvalues and rvalues

value categories :l-value vs r-value

l-value has a name , a identity

ampersand &

auto&& v4 = v1 + v2; // r-value reference = r-value
两个&&表示右值引用,延长了r-value v1+v2的寿命

const auto& ptr3 = ptr +5; // const l-value = r-value
non-const value doesn't work but const

## why r-values are key to move semantics

a object that is l-value is NOT disposable

r-value is disposable

disposable 一次性的

## 2 new special member functions

Default constructor
Copy constructor (create new from existing l-value )
Copy assignment (overwrite existing from existing l-value)
Destructor

Move constructor (create new from existing value)
Move assignment (overwrite existing from existing r-value)

## 右值引用的应用

Move constructor and Move assignment function

减少copy

std::move(),将一个左值强制转化成右值

### 移动构造函数

```cpp
class SimpleString {
public:
    char* data;
    explicit SimpleString(size_t length) 
        : data(new char[length]) { /* 初始化代码 */ }

    ~SimpleString() {
        delete[] data;
    }

    // 移动构造函数
    SimpleString(SimpleString&& other) noexcept 
        : data(other.data) {
        other.data = nullptr;  // 留下一个安全的状态
    }

    // 禁用拷贝构造函数（C++11 之后的做法）
    SimpleString(const SimpleString&) = delete;

    // 其他成员函数...
};
```

## homework:write a swap function

```cpp
vector<string> v1("En",114514);
vector<string> v2("ito",1000000);
swap(v1,v2);
```

solution

```cpp
#include <utility> // std::move
void swap(vector<string> &v1,vector<string> &v2)
{
    vector<string> tmp = std::move(v1);
    v1 = std::move(v2);
    v2 = std::move(tmp);
}
```
