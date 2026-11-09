#include<iostream>
#include"FLinkedList.hpp"
#include<cstdio>
using namespace std;
int main()
{
    FLinkedList<int> a;
    // 第一个点
    // 插入 访问
    for (int i=0;i<10;i++)
        a.insert(i,i);
    
    for (int i=0;i<10;i++)
        cout<<a.at(i)<<" ";
    cout<<endl;
    // 第二个点
    // 删除 插入 访问
    for (int i=0;i<10;i++)
        a.erase(0);
    for (int i=0;i<10;i++)
        a.insert(66,i);
    for (int i=0;i<10;i++)
        cout<<a.at(i)<<" ";
    cout<<endl;
    // 第三个点
    // 试试 append 元素
    for (int i=0;i<10;i++)
        a.append(i);
    for (int i=0;i<20;i++)
        cout<<a.at(i)<<" ";
    cout<<endl;
    
    // 第四个点
    // 试试 append 串
    FLinkedList<int> b;
    for (int i=0;i<10;i++)
        b.append(i+20);
    a.append(b);
    for (int i=0;i<30;i++)
        cout<<a.at(i)<<" ";
    cout<<endl;
    
    // 第五个点
    // 试试翻转
    a.converse();
    for (int i=0;i<30;i++)
        cout<<a.at(i)<<" ";
    cout<<endl;
    return 0;
}