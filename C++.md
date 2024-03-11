# C++ 面试题

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

    地址解析协议（ARP）是网络层到数据链路层的地址转换协议，用于将IP地址转换为MAC地址。

    工作原理：
        ARP请求：在局域网内广播请求，询问目标IP地址对应的MAC地址。
        ARP响应：拥有该IP地址的设备回应其MAC地址。
        通信：发送方收到响应后，将IP和MAC地址映射存储于ARP缓存表，实现数据链路层的通信。
        ARP缓存表：存储IP地址到MAC地址的映射关系，动态更新，保证通信的准确性。

    重要性：
    使得基于IP的网络层通信能通过数据链路层实现。
    对局域网内设备进行通信至关重要。
    需要注意ARP欺骗等安全风险。

8.多态原理

9.STL

10.内存泄漏,怎么解决
    (1)什么是内存泄露？
    程序在申请内存后，未能在不再需要时释放，
    导致程序运行过程中逐渐消耗更多的内存，最终可能导致程序运行缓慢或崩溃
    
    (2)写代码时遵循RAII原则，使用智能指针std::unique_ptr,std::shared_ptr
    查找未匹配的new delete，未关闭的文件句柄或数据库连接等

    (3)使用VS内存诊断工具检查及定位堆栈发生的位置

11.const reference
    定义
    const int& ref = someInt; //通过ref不能改变someInt的值

    const reference可以绑定临时值,如函数返回值,普通引用则不能
    const int& ref = someFunctionReturningInt();

    double pi = 3.14;
    const int& ref = pi;

    作为函数参数
    void myFunction(const int& x);

12.when to use reference to pass parameters?
    You should not  copy the parameter p if sizeof(p) >= 4 * sizeof(int)
    You should not use a const reference to p if sizeof(p) < 4 * sizeof(int)

13.tcp/ip

14.tcp的三次握手

    (1)SYN（同步序列编号）：在建立连接的开始，客户端发送一个SYN（同步序列编号）报文给服务器。这个报文里包含一个客户端随机产生的序列号（我们假设为序列号x）。这个序列号用于同步序号以便于之后的数据传输。

    (2)SYN-ACK（同步确认）：服务器收到客户端的SYN报文后，会返回一个SYN-ACK报文。这个报文包含两部分信息：一是ACK（确认字符），它确认客户端的SYN（即确认号为x+1，表示服务器期待接收客户端后续报文的序列号），二是服务器自己的SYN报文，包含服务器随机产生的序列号（我们假设为序列号y）。

    (3)ACK（确认）：客户端收到服务器的SYN-ACK报文后，会发送一个ACK报文作为回应。这个ACK报文的序列号是y+1。

15.回调函数 callback function
    一种在程序运行中通过函数指针调用的函数,在运行时决定调用哪个函数，非常适合事件驱动或异步编程
    (1)定义函数指针
    tyepdef void (*Callback)(int) # C

    #include<functional>
    using Callback = std::function<void(int)> # C++
    以上两种方式定义了一个返回类型为void，参数为一个int的函数指针

    (2)使用
    void ProcessEvent(int eventData, Callback callback_fuction)
    {
        callback_function(eventData);
    }

    /// 使用lambda表达式作为回调函数
    ProcessEvent(5, [](int data) {
        std::cout << "Lambda callback with data: " << data << std::endl;
    });
    
    // 使用具体函数作为回调
    auto concreteCallback = [](int data) {
        std::cout << "Another lambda callback with data: " << data << std::endl;
    };
    ProcessEvent(10, concreteCallback);
