#include<iostream>
using namespace std;
#include "Stack.hpp"
int main()
{
    /*
    栈满栈空的情况，助教都已经处理好了。
    因此下面也不测试这些情况了。
    */
    Stack<int> a(20);
    // 先压入10个元素
    for (int i=0;i<10;i++)
    {
        int x;
        cin>>x;
        a.push(x);
    }
    // 弹空
    while(!a.isEmpty())
        a.pop();
    // 再压10个
    for (int i=0;i<10;i++)
    {
        int x;
        cin>>x;
        a.push(x);
    }
    // 弹出5个
    for (int i=0;i<5;i++)
        a.pop();
    // 再压10个
    for (int i=0;i<10;i++)
    {
        int x;
        cin>>x;
        a.push(x);
    }
    // 输出栈中所有东西
    while(!a.isEmpty())
    {
        cout<<a.top()<<endl;
        a.pop();
    }    
    return 0;
}