# STL

predicate-->lambda function

```cpp
#include<iostream>
#include<iterator> // ostream_iterator
#include<algorithm> // transform

using std::cout;
using std::endl;

// 接下来很有讲头
while (std::getline(file,line))
{ 
    // getline实际上返回的是一个stream
    // 但是stream可以隐式地转换为bool，表示输入是否成功
    // 以此可读取整个文件
    // 但是！不建议再在循环里读取文本！可能会影响到外面的循环！
    std::transform(line.begin(), line.end(), std::ostream_iterator<char>(cout, ","), ::tolower);
    // transform是algorithm里的一个有用的算法，相当于对一段range进行for循环，然后对每个元素采取操作
    // 前两个参数表示开始点和结束点
    // 第四个参数是转小写，前面的::是表示全局空间里的作用域符，可以不加
    // 第三个参数是一个iterator adapter，它会将转为小写后的char送到绑定的cout这个ostream里，并且每个以“，”间隔
    
}
```

## transform

```cpp
template< class InputIt, class OutputIt, class UnaryOperation >
OutputIt transform( InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation unary_op );
```
