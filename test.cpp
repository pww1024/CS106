#include<iostream>
#include<map>
#include<set>

int main()
{
    std::map<int, int> m={{1,2},{3,4},{5,6}};

    for(auto it=m.begin(); it!=m.end(); ++it) // it type is std::map<int, int>::iterator
    {
        const auto& [key, value]=*it;
        // std::cout<<it->first<<" "<<it->second<<std::endl; // maps store pairs
        std::cout<<key<<" "<<value<<std::endl;
    }

    std::set<int> s={1,2,3,4,5,6,7,8,9,10};

    for(const auto& elem: s)
    {
        std::cout<<elem<<std::endl;
    }

    return 0;
}