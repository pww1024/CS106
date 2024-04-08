# Operator overload

1.对于一些特殊操作符，+=，要返回该对象的引用，return *this;
重载+后也要重载-，符合直觉

2.重载二元对称操作符时，+，-，要将他们作为非成员函数

3.实现const版本和non-const版本
因为const对象只能调用const版本的函数
例如vector的[]操作符
