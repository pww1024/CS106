# Containers

## Sequence Containers

includes:
std::vector<T>
std::deque<T>
std::list<T>
std::array<T>
std::forward_list<T>

segmentation fault
C plus plus dont check bounds

deque vs vector
push_front

difference vec.at(index) vec[index]
vec.at() throws an exception
vec[] causes undefined behavior

## Container adaptors

stack,queue,...

adaptor means 
a wrapper to the underlying container
and same Modifiers with vector or deque

## Associative Containers

if have no word in keys
frequencyMap[word] // automatically create an entry and default initialize it,0
frequencyMap.at(word) // throw

check the key in the Map
frequencyMap.count(word)

## iterator

std::sort(vec.begin(),vec.end());

auto result_it = std::find(set.begin(),set.end(),ELEM_TO_FIND);
if(result_it==set.end())

5 different types of iterators
Input,Output <-- Forward <-- Bidirectional <-- Random access
meaning of <-- is superset

think about pointers as a sort of a specific class
iterator : a set of promises
