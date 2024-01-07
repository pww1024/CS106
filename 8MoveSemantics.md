# Move Semantics

## vec.emplace_back

for efficient

`https://en.cppreference.com/w/cpp/container/vector/emplace_back`

## copy elision

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

## homework:write a swap function

```
vector<string> v1("En",114514);
vector<string> v2("ito",1000000);
swap(v1,v2);
```
