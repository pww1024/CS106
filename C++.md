# C++ notes

## 面试题

0.qt开发

1.内存对齐

#pragma pack(n) 
__attribute__((packed))

2.重载
    汇编出来的汇编代码只是更改函数名称

3.C++11以上特性
    auto直接用于变量前,decltype(exp) var
    匿名函数Lambda
    nullptr
    右值引用与std::move
    智能指针std::shared_ptr和std::unique_ptr
    引入线程库std::thread

4.主流编译器
    GNU (GCC)
    Clang
    Microsoft Visual C++

5.智能指针
    遇到的问题:
        动态创建某个对象时,在程序结束时没有调用delete,则不会自动调用析构函数
    解决:智能指针

    头文件<memory> std

    C++98
        auto_ptr
    例子:
    std:auto_ptr<Test> test(new Test);
    声明一个叫test的智能指针

    智能指针的三个常用函数:
    get() 获取智能指针托管的指针地址
    release() 取消智能指针对动态内存的托管 Test *tmp2 = test.release()
    reset() 重置智能指针托管的内存地址

    C++11 (auto_ptr已被抛弃)
        std::unique_ptr
        std::shared_ptr
        std::weak_ptr


7.ARP协议

8.多态原理

9.STL

10.内存泄漏,怎么解决

11.const reference
定义
const int& ref = someInt; //通过ref不能改变someInt的值

const reference可以绑定临时值,如函数返回值,普通引用则不能
const int& ref = someFunctionReturningInt();

double pi = 3.14;
const int& ref = pi;

作为函数参数
void myFunction(const int& x);


