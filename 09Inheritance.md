# Inheritance

`https://en.cppreference.com/w/cpp/language/operators`

## challenge mode

const int* const myClassMethod(const int* const & param) const;

## Namespaces

## Interface 

interface is a subset of inheritance

```
class Drink
{
    public:
        virtual void make() = 0; // pure function
        virtual void cook(); // non-pure function
        void bar()={return 42;}; // regular function
};

class Tea : public Drink
{
    public:
        void make()
        {
            // implementation
        }
};
```

pure virtual function

## Abstract Classes

if a class has at least one pure virtual function,
then it's called an `abstract class`

abstract classes cannot be instantiated 实例化

## struct inheritance

```
struct A
{
    int a;
};

struct B
{
    double a; // hides A::a, for all no 'virtual' members
};
```

all resource are inherited by `public`
