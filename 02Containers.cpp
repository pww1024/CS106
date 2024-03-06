# include<iostream>
# include<map>
# include<string>
# include<set>
# include<algorithm>

using std::string;
using std::map;
using std::cout;
using std::endl;

map<string,int> readUserWords()
{
    map<string, int> wordMap;
    string word;
    while(std::cin >> word)
    {
        ++wordMap[word];
    }
    return wordMap;
}

void printElement1(const map<string,int> &wordMap)
{
    map<string,int>::const_iterator mapIt = wordMap.begin();
    while(mapIt != wordMap.end())
    {
        cout << mapIt->first << " : " << (*mapIt).second << endl;
        ++mapIt;
    }
}

void printElement2(const map<string,int> &wordMap)
{
    for(const auto &elem : wordMap) // elem type is pair<const string,int>
    {
        cout << elem.first << " : " << elem.second << endl;
    }
}

void printElement3(const map<string,int> &wordMap)
{
    for(const auto [key,val] : wordMap)
    {
        cout << key << " : " << val << endl;
    }
}



int main()
{
    map<string,int> frepMap = readUserWords();
    printElement1(frepMap);
    printElement2(frepMap);
    printElement3(frepMap);

    // std::sort();

    return 0;
}