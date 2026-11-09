#include<iostream>
using namespace std;
#include"Queue.hpp"
int main()
{
    /*
    队列满与空的情况，助教都已经处理好了。
    因此下面也不测试这些情况了。
    */
    Queue<int> a(20);
    // 先入10个元素
    for (int i=0;i<10;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    // 弹空
    while(!a.isEmpty())
        a.pop_front();
    // 再压10个
    for (int i=0;i<10;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    // 弹出5个
    for (int i=0;i<5;i++)
        a.pop_front();
    // 再压10个
    for (int i=0;i<10;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    // 输出栈中所有东西
    while(!a.isEmpty())
    {
        cout<<a.front()<<endl;
        a.pop_front();
    }    
    return 0;
}