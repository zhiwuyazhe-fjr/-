/*******************************************************************************
* FileName:         LinkedList.hpp
* Author:           冯桥
* Student Number:   3017216006
* Date:             2021/03/23 23:03:22
* Version:          v1.0
* Description:      Data Structure Experiment #2.2
*                   请补全LinkedList类。请实现为双向循环链表
*******************************************************************************/
#ifndef LinkedList_H
#define LinkedList_H
#include<algorithm>
#include <iostream>
using namespace std;
template<class T> class LinkedList
{
public:
    struct Node{
        T value;
        Node* pre;
        Node* next;
        Node() {}
        Node(T _value, Node* _pre, Node* _next) : value(_value), pre(_pre), next(_next) {}
    };
    
    // 头结点
    Node* head;
    
    // 链表长度
    int len;

    /**
        构造函数，构建一个 LinkedList。
        @name LinkedList();
    */
    LinkedList()
    {
        // 做成双向循环链表
        len = 0;
        head = new Node();
        head->pre = head;
        head->next = head;
    }

    /**
        析构函数
        @name ~LinkedList();
        -------------------------------------------------------
        记得把所有结点都释放哦，小心内存泄漏。
    */
    ~LinkedList()
    {
        Node * tmp;
        Node * now = head;
        // 一共 len+1 个结点（头结点 + len 个数据结点），都要释放
        for (int i=0;i<=len;i++)
        {
            tmp = now->next;
            delete now;
            now = tmp;
        }
    }

    /**
        询问LinkedList现有元素的个数
        @name length();
        @return int 当前LinkedList包含元素的个数
    */
    int length()
    {
        return len;
    }

    /**
        获取location位置的元素（从0开始标号)
        @name at(int);
        @param  location 需要查询元素的位置
        @return int LinkedList在location位置的元素
    */
    T at(int location)
    {
        if (location < 0 || location >= len)
        {
            // 下标非法，简单返回头结点的值（也可以选择报错退出）
            return head->value;
        }
        // 似乎照抄单链表就行呢
        // 从头结点往后走 location 步，就是第 location 个元素
        Node* now = head->next;
        for (int i = 0; i < location; i++)
        {
            now = now->next;
        }
        return now->value;
    }

    /**
        插入元素
        @name insert(T&, int);
        @param  data        需要插入的元素
                location    插入元素的位置
        @return bool    true 插入成功，false插入失败
        ----------------------------------------------------------
        插入失败是指location不对的情况
    */
    bool insert(const T& data, int location)
    {
        if (location < 0 || location > len)
        {
            // 位置越界，插入失败
            return false;
        }
        // 找到 location 的前驱：从头结点往后走 location 步
        Node* now = head;
        for (int i = 0; i < location; i++)
        {
            now = now->next;
        }
        // 新结点挂到前驱和后继之间（循环链表，插表尾时后继就是头结点，同样适用）
        Node* tmp = new Node(data, now, now->next);
        now->next->pre = tmp;
        now->next = tmp;
        len = len + 1;
        return true;
    }

    /**
        删除位于location的元素
        @name erase(int);
        @param  location 需要删除元素的位置
        @return bool    true 删除成功，false删除失败
        ----------------------------------------------------------
        删除失败是指location不对的情况
    */
    bool erase(int location)
    {
        if (location < 0 || location >= len)
        {
            // 位置越界，删除失败
            return false;
        }
        // 找到 location 的前驱
        Node* now = head;
        for (int i = 0; i < location; i++)
        {
            now = now->next;
        }
        // 前驱和后继互相指起来，被删结点从环里摘出来（删表尾时后继是头结点，同样适用）
        Node* tmp = now->next;
        now->next = tmp->next;
        tmp->next->pre = now;
        delete tmp;
        len = len - 1;
        return true;
    }

    /**
        将链表进行翻转操作。
        @name converse();
        ---------------------------------------------------------
        例如， LinkedList开始为 1 2 3 4 5，
        则翻转后为  5 4 3 2 1
    */
    void converse()
    {
        /*
            其实把所有的pre和next互换就行了，比单链表简单
         */
        // 连头结点在内一共 len+1 个结点，每个都把 pre 和 next 互换
        // 注意要沿着换之前的 next 方向走，才能遍历完整个环
        Node* now = head;
        for (int i = 0; i <= len; i++)
        {
            Node* tmp = now->next;
            Node* t = now->pre;
            now->next = t;
            now->pre = tmp;
            now = tmp;
        }
    }

    /**
        将data插入到链表表尾。
        @name append(T&);
        @param data 要插入的元素。
    */
    void append(const T& data)
    {
        // 请直接插入表尾，注意时间复杂度要求是O(1)的。
        // 为什么没有维护last呢？别忘了我们是双向循环链表。
        Node* tmp = new Node(data,head->pre,head);
        head->pre->next = tmp;
        head->pre = tmp;
        len++;
    }

    /**
        将append_list拼接到当前链表后，拼接后append_list将为空链表
        @name append(LinkedList&);
        @param  append_list 被拼接的链表。
    */
    void append(LinkedList &append_list)
    {
        if (append_list.len == 0 || &append_list == this)
        {
            // 空表（或自己拼自己）没有数据结点可搬
            return;
        }
        // 对方环上的首尾数据结点
        Node* first = append_list.head->next;
        Node* tail = append_list.head->pre;
        // 本表尾(head->pre)接对方首结点，对方尾结点接回本表头，接成一个环
        head->pre->next = first;
        first->pre = head->pre;
        tail->next = head;
        head->pre = tail;
        len = len + append_list.len;
        // 数据结点全部搬走后，对方重置为空表（头结点保留）
        append_list.head->next = append_list.head;
        append_list.head->pre = append_list.head;
        append_list.len = 0;
    }

    /**
        将链表元素顺序输出。
        @name print();
        ---------------------------------------------------------
        本函数在测试中不会被调用，仅为方便大家调试。
    */
    void print()
    {
        Node* now = head;
        for (int i=0;i<len;i++)
        {
            now = now->next;
            cout<<now->value<<endl;
        }
    }
};
#endif