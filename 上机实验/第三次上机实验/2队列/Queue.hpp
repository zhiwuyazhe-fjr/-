/*******************************************************************************
* FileName:         Queue.hpp
* Author:           冯桥
* Student Number:   3017216006
* Date:             2021/03/31 14:03:22
* Version:          v1.0
* Description:      Data Structure Experiment #3.2
*******************************************************************************/
#ifndef QUEUE_H
#define QUEUE_H
template<class T> class Queue
{
public:
    T* a;
    // head是头，也就是front的位置
    // tail是尾，也就是back的位置
    // lim是容量大小
    int head,tail,lim;
    Queue(int size)
    {
        if (size<2) size = 2;
        a = new T[size];
        lim = size;
        head=0;
        tail=0;
    }
    ~Queue()
    {
        delete [] a;
    }
    bool push_back(const T& data)
    {
        // 注意：要判断队列是不是满了
        // 我们是循环队列，所以要留一个元素不能满上！
        // head==tail是空的意思，下面是满了的意思
        if ((tail+1)%lim == head) return false;

        // your code here
        a[tail++] = data;
        // 注意：做成循环的队列！
        // 所以tail到头了要从0再往后, 就是下面这句
        if (tail==lim) tail=0;
        return true;
    }
    void pop_front()
    {
        if (head==tail) return; // 空了就算了
        
        // your code here
        head++;
        // 注意：做成循环的队列！
        // 所以head到头了要从0再往后, 就是下面这句
        if (head==lim) head=0;
    }
    T front()
    {
        // your code here
        // 下面这句要改！！！
        return a[head];
    }

    bool isEmpty()
    {
        // 这个不用大家写了
        return head==tail ? true : false ;
    }

};
#endif