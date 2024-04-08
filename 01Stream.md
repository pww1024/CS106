# Streams

## stringstream

ostringstream 联想到 cout，istringstream 则联想到 cin

### When should use stringstream?

- Processing strings
- Formatting input/output
- Parsing different types

When u want to just concatenate some strings, it’s faster to use str.append()!!

## ostringstream使用场景

`#include<sstream>` 头文件

1. 数字到字符串的转换

```cpp
std::ostringstream oss;

oss << std::fixed << std::setprecision(2) << number; 
std::string numberStr = oss.str();
```

fixed指定输出不使用科学计数法，setpricision保留2位有效数字

2. 生成动态SQL查询或JSON字符串

```cpp
// SQL查询伪代码
std::ostringstream sql;
sql << "SELECT * FROM users WHERE age > " << minAge << " AND age < " << maxAge;
std::string query = sql.str();
// JSON字符串伪代码
std::ostringstream json;
json << "{ \"name\": \"" << name << "\", \"age\": " << age << " }";
std::string jsonString = json.str();
```

## stream的4种状态

![ ](/picture/FourStatesInStream.png "")

## stream的buffer机制

![ ](/picture/FourStandardIostream.png)
std::cerr全缓存

## 对于cout

endl会直接刷新整个缓冲区，'\n'只是将换行符放入缓冲区
在大量IO输出的情况下使用'\n'换行效率更高
endl比`/n'更低效1/3

i，o stringstream的区别，string To Integer实现，result初始化0

## 检查一个stream的状态

```cpp
void printBitInfo(istream& s) {
    cout << "State bits: ";
    // stream的四种状态
    cout << (s.good() ? "G" : "-"); // 表示输入正常，可继续接受输入
    cout << (s.fail() ? "F" : "-"); // 表示输入出现异常(Type mismatch, file can't be opened, seekg failed, so on)，未来不可以继续接受输入
    cout << (s.eof() ? "E" : "-"); // Reach the end
    cout << (s.bad() ? "B" : "-"); // Couldn't move characters to buffer from external resource(e.g. the file is suddenlt deleted)

    cout << endl;
}
```

## void badWelcomeProgram()

badWelcomeProgram中,当一次性输入Avery Wang\n 到buf中,
第一个cin接收Avery,指针停到writespace前,第二个cin调用时skip这个writespace,but not consume it
当试图用int类型的age接收Wang时,fail bit会打开,然后cin停止工作,指针停在Wang前

## getline 函数的含义

getline read up to newline character and consume the newline character

## 有符号与无符号进行比较

annoying warning message about unsigned integerd

```CPP
string str("hello world");
for(int i=0;i<str.size();i++) // str.size()是size_t类型的
    cout<<str[i]<<endl;
```

在比较i和str.size()时，i会被隐式转换为size_t类型，
在i为负值时，会被转换为非常大的值

尽量让编译器使用更严格的选项-Wall，保持一个好的代码习惯

## 多进程程序的stream

多进程程序中,每个进程都有自己的内存空间和系统资源，包括输入输出缓冲区。
当多个进程需要从同一个物理输入源（如键盘、文件等）读取数据时，
它们各自的输入缓冲区（cin的缓冲区）会试图从该物理源获取数据，这就可能导致竞争条件（race condition）。

### 解决办法

为了避免这种竞争条件，一种常见的设计模式是让父进程（或某个特定进程）负责执行所有的输入操作，即父进程独自从物理输入源读取数据。
然后，父进程通过进程间通信（IPC，Inter-Process Communication）机制，
如管道（pipes）、消息队列、共享内存、信号量等，将输入数据传递给其他子进程。

## Type

```cpp
// 像下面的type表示起来很麻烦，还很容易报错
std::unordered_map<forward_list<Student>,unordered_set>::iterator begin = studentMap.cbegin();
// 该怎么解决呢？
// Method 1,name alias
using map_iterator = std::unordered_map<forward_list<Student>,unordered_set>::iterator;
map_iterator end = studentMap.cend(); // .cend() 常量constant迭代器，不能修改容器中的内容
// Method 2,auto
auto autoEnd = studentMap.end();
```

auto discards const and references

### 使用auto构造lambda function

`auto func=[](auto i){return i*2;};`
