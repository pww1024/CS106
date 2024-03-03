#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>

int test()
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


int main() 
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {1, 2, 3, 4, 5};

    // 1. using for loop
    for (const auto& elem : vec) 
        std::cout << elem << ' ';
    std::cout << "\n";

    // 2. using algorithm method with lambda
    std::for_each(vec.begin(), vec.end(),
        [](const int& n) { std::cout << n << ' '; });
    std::cout << "\n";

    std::copy(vec2.begin(),vec2.end(),std::back_inserter(vec));

    // 3.copy output to ostream iterator
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<"\n";

    return 0;
}