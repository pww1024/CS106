#include<iostream>
#include<string>
#include<list>
#include<utility>

using std::cout;
using std::endl;
using std::string;
using std::list;
using namespace std::string_literals; // necessary for "s" suffix
using std::pair;

template<typename T>
pair<T, T> my_minmax(T a, T b) 
{
    if (a < b) return {a, b};
    else return {b, a};
}


void my_printf(string format)
{
    cout<<format<<endl;
    return;
}

// 如果模板声明过多而不使用,会报错
template<typename T, typename ...Ts>
void my_printf(string format, T value, Ts... args) 
// recursive variadic function 递归 可变参数 模板函数
{
    string::size_type pos=format.find("%"); // 注意find返回的pos类型

    if (pos==string::npos) // if no more value needed be inserted
    {
        my_printf(format); // print the rest of the format
        return;
    }   
    else
    {
        cout<<format.substr(0,pos)<<value;
        my_printf(format.substr(pos+1),args...);
        return;
    }
}

template<typename T, typename ...Ts>
void my_printf1(string format, T value, Ts... args) // implement from ppt
{
    string::size_type pos=format.find("%");
    if (pos==string::npos)
    return;
    cout<<format.substr(0,pos)<<value;
    my_printf(format.substr(pos+1),args...);
}

template <typename InputIt,typename DataType>
int count0ccurences(InputIt begin,InputIt end,DataType value)
{
    int count=0;
    for(auto it=begin;it!=end;it++)
    {
        if(*it==value)
            count++;
    }
    return count;
}

template <typename InputIt, typename UniPred>
int count0ccurences1(InputIt begin,InputIt end, UniPred predicate)
{
    int count=0;
    for(auto it=begin;it!=end;it++)
    {
        if(predicate(it))
            count++;
    }
    return count;
}

template <typename T>
auto printSize(const T& a) ->decltype(a.size(), size_t()) // size_t() 可省
// decltype 用于定义一个函数模板的返回类型
// 作用是检查a对象否有.size()方法,如果有，这个函数将返回 size_t 类型的值
// 典型SFINAE用法
{
    cout << "printing with size member function: ";
    cout << a.size() << endl;

    return a.size();
}

int main()
{
    auto [min, max] = my_minmax("“Anna”", "“Avery”"); // structured binding
    cout<<min<<" "<<max<<endl;

    // Lecture 7: Templates (Week 4)
    my_printf1("Lecture %: % (Week %)"s, 7, "Templates"s, 4);
    
    list<int> list{1,1,4,5,1,4};
    cout<<count0ccurences(list.begin(),list.end(),1)<<endl;
    
    printSize(list);

    return 0;
}
