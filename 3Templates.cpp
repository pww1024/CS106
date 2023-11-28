#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;
using namespace std::string_literals; // necessary for "s" suffix

void my_printf(string format)
{
    cout<<format<<endl;
    return;
}

template<typename T, typename ...Ts>
void my_printf(string format, T value, Ts... args) 
// recursive variadic function
{
    int pos=format.find("%");

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
void my_printf1(string format, T value, Ts... args)
{
    int pos=format.find("%");
    if (pos==string::npos)
    return;
    cout<<format.substr(0,pos)<<value;
    my_printf(format.substr(pos+1),args...);
}

int main()
{
    // Lecture 7: Templates (Week 4)
    my_printf1("Lecture %: % (Week %)"s, 7, "Templates"s, 4);
    
    return 0;
}
