/*******************************************************************************
* FileName:         FLinkedList.hpp
* Author:           冯桥
* Student Number:   3017216006
* Date:             2021/03/23 22:47:53
* Version:          v1.0
* Description:      Data Structure Experiment #2.1
*                   请补全FLinkedList类。FLinkedList即单链表，指Forward Linked List。
                    因为单链表只能正向遍历（无法快速求前驱），因此称之为Forward。
*******************************************************************************/
#ifndef FLinkedList_H
#define FLinkedList_H
#include<iostream>
using namespace std;
template<class T> class FLinkedList
{
public:
    struct Node{
        T value;
        Node* next;
        // 这是Node结构体的构造函数，方便你下面调用。
        Node() {}
        Node(T _value, Node* _next) : value(_value), next(_next) {}
    };
    
    // 头结点
    /**
        记得复习：为什么需要头结点？带头结点的好处是什么？
    */
    Node* head;
    
    // 尾指针
    /**
        一般都是向表尾添加元素。因此这里额外维护一个尾指针。
        PPT里有提到过尾插法和尾指针哦！后面 void append(T& data) 会用到。
    */
    Node* last;
    
    // 链表长度
    /**
        一般会顺手维护一个链表长度，这样求元素个数就很方便。
    */
    int len;

    /**
        构造函数，构建一个 FLinkedList。
        @name FLinkedList();
        ---------------------------------------------------
        为了防止同学们不知道该干什么，助教决定把它实现了。
        但是记得复习：创建一个链表时需要做什么？
    */
    FLinkedList()
    {
        // 创建链表要做的就是把头结点安排好
        len = 0;
        head = new Node(0, NULL);
        last = head;
    }

    /**
        析构函数
        @name ~FLinkedList();
        -------------------------------------------------------
        记得把所有结点都释放哦，小心内存泄漏。
    */
    ~FLinkedList()
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
        询问FLinkedList现有元素的个数
        @name length();
        @return int 当前FLinkedList包含元素的个数
    */
    int length()
    {
        return len;
    }

    /**
        获取location位置的元素（从0开始标号)
        @name at(int);
        @param  location 需要查询元素的位置
        @return int FLinkedList在location位置的元素
    */
    T at(int location)
    {
        if (location < 0 || location >= len)
        {
            // 下标非法，简单返回头结点的值（也可以选择报错退出）
            return head->value;
        }
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
    bool insert(const T &data, int location)
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
        // 新结点接在前驱后面
        now->next = new Node(data, now->next);
        if (location == len)
        {
            // 插在了表尾，尾指针要跟着更新
            last = now->next;
        }
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
        // 前驱的 next 跳过被删结点
        Node* tmp = now->next;
        now->next = tmp->next;
        if (location == len - 1)
        {
            // 删的是表尾，尾指针退到前驱（表删空时前驱就是头结点）
            last = now;
        }
        delete tmp;
        len = len - 1;
        return true;
    }

    /**
        将链表进行翻转操作。
        @name converse();
        ---------------------------------------------------------
        例如， FLinkedList开始为 1 2 3 4 5，
        则翻转后为  5 4 3 2 1
    */
    void converse()
    {
        if (len == 0)
        {
            return;
        }
        // 从第一个元素开始，让每个结点的 next 反过来指向前驱
        Node* prev = NULL;
        Node* now = head->next;
        while (now != NULL)
        {
            Node* tmp = now->next;
            now->next = prev;
            prev = now;
            now = tmp;
        }
        // 走完后 prev 是原来的表尾；原来的第一个元素变成了新表尾
        last = head->next;
        head->next = prev;
    }

    /**
        将data插入到链表表尾。
        @name append(T&);
        @param data 要插入的元素。
    */
    void append(const T& data)
    {
        // 请直接插入表尾，注意时间复杂度要求是O(1)的，借助上面维护的last指针完成。
        // 新结点直接接在尾指针后面，不用遍历
        last->next = new Node(data, NULL);
        last = last->next;
        len = len + 1;
    }

    /**
        将append_list拼接到当前链表后，拼接后append_list将为空链表
        @name append(FLinkedList&);
        @param  append_list 被拼接的链表。
    */
    void append(FLinkedList &append_list)
    {
        // append_list.head是被拼接元素的头结点
        // 保持冷静：首先保证本链表是对的
        if (append_list.len == 0 || &append_list == this)
        {
            // 空表（或自己拼自己）没有数据结点可搬
            return;
        }
        // 本表尾接上对方第一个元素，本表尾指针改成对方表尾
        last->next = append_list.head->next;
        last = append_list.last;
        len = len + append_list.len;
        // 数据结点全部搬走后，对方重置为空表（头结点保留）
        append_list.head->next = NULL;
        append_list.last = append_list.head;
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