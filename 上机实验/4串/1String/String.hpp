/*******************************************************************************
* FileName:         String.hpp
* Author:           冯桥
* Student Number:   3017216006
* Date:             2021/04/07 11:33:09
* Version:          v1.0
* Description:      Data Structure Experiment #4.1
*******************************************************************************/
#ifndef STRING_H
#define STRING_H
#include <cstring>
class String
{
public:
    char* a;    // 存串
    int len;    // 长度，a数组大小（上限）

    // 建议使用c风格的。
    // 不用亦可，记得后面小改。
    
    String() // 空串
    {
        len=0;
        a = new char[1];
        a[0]='\0';
    }
    
    String (const String &b)
    {
        len = b.len;
        a = new char[len+1];
        for (int i=0;i<=len;i++)
        a[i] = b.a[i];
    }

    String(const char* str) // 初始化串
    {
        len = strlen(str);
        a = new char[len+1];
        for (int i=0;i<=len;i++)
        {
            a[i] = str[i];
        }
    }

    ~String() // 析构函数
    {
        delete [] a;
    }

    int length() // 长度
    {
        return len;
    }

    const char * c_str() // 返回c风格字符串
    {
        return a;
    }

    String subString(int begin, int count) // 提取子串
    {
        // 这个函数要改
        // begin是起始下标
        // count是子串长度
        return String();
    }

    void append(const String & str) // 字符串拼接
    {
        // 这个函数要改
    }

    int find(const String & str) // 查找子串
    {
        // 这个函数要改
        return -1;
    }
};
#endif