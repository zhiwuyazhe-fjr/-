#include<iostream>
#include"String.hpp"
using namespace std;
char a[10010];
char b[10010];
int main()
{
    // 测试find
    for (int i=0;i<5;i++)
    {
        cin>>a;
        cin>>b;
        String aa(a);
        String bb(b);
        cout<<aa.find(bb)<<endl;
    }
    // 测试append
    for (int i=0;i<5;i++)
    {
        cin>>a;
        cin>>b;
        String aa(a);
        String bb(b);
        aa.append(bb);
        cout<<aa.c_str()<<endl;
        cout<<bb.c_str()<<endl;
    }
    // 测试subString
    for (int i=0;i<5;i++)
    {
        int begin, count;
        cin >> a;
        cin >> begin >> count;
        String aa(a);
        String bb = aa.subString(begin,count);
        cout<<bb.c_str()<<endl;
    }
    return 0;
}