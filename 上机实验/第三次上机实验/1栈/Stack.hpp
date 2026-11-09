/*******************************************************************************
* FileName:         Stack.hpp
* Author:           冯桥
* Student Number:   3017216006
* Date:             2021/03/31 14:01:36
* Version:          v1.0
* Description:      Data Structure Experiment #3.1
*******************************************************************************/
#ifndef STACK_H
#define STACK_H
template<class T> class Stack
{
public:
    /*
        a是你的序列表
        len是栈中元素个数
        lim是栈大小
     */
    T* a;
    int len,lim;

    Stack(int size)
    {
        a = new T[size];
        len = 0;
        lim = size;
    }
    ~Stack()
    {
        delete [] a;
    }

    bool push(const T& data)
    {
        if (len==lim) return false; // 栈满了
        a[len++] = data;
        return true;
        // your code here
    }

    void pop()
    {
        if (len==0) return; // 栈空了
        len--;
    }

    T top()
    {
        return a[len-1];  
    }

    bool isEmpty()
    {
        return len==0 ? true : false ;
    }
};
#endif