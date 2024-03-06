# Streams

p2 p3 video

## p2

extraction operator >>

ostringstream oss("def", ostring stream::ate);这个操作是什么意思？

buf底层实现

i，o stringstream的区别，string To Integer实现，result初始化0

stream状态

检查是否eof

iss>>result 
return stream and convert to fail bit

std::cerr全缓存

endl比`/n'更低效1/3

## p3

badWelcomeProgram中,当一次性输入Avery Wang\n 到buf中,
第一个cin接收Avery,指针停到writespace前,第二个cin调用时skip这个writespace,but not consume it
当试图用int类型的age接收Wang时,fail bit会打开,然后cin停止工作,指针停在Wang前

getline read up to newline character and consume the newline character

annoying warning message about unsigned integerd
```
string str("hello world");
for(int i=0;i<str.size();i++) 
    cout<<str[i]<<endl;
```
2 warning,compare,index
int --> size_t

auto
auto discards const and references
lambda func
`auto func=[](auto i){return i*2;};`

extra:
多进程程序中,每个进程都有自己的cin buf,逻辑上读取自同一个物理输入源(竞争同步problem)
让父进程负责所有输入操作，然后通过进程间通信将输入数据传递给其他进程
