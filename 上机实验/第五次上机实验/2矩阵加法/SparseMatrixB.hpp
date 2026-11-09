#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include <cstdio>
#include <iostream>
using namespace std;
class SparseMatrix
{
public:
    int maxSize;    // 最多能存多少非零元素
    int rn, cn, vn; // 行数、列数、非零元素个数
    int *row; // 行号
    int *col; // 列号
    int *val; // 值

    SparseMatrix(const SparseMatrix &a)
    {
        maxSize = a.maxSize;
        rn = a.rn;
        cn = a.cn;
        vn = a.vn;
        row = new int[maxSize+1];
        col = new int[maxSize+1];
        val = new int[maxSize+1];
        for (int i=1;i<=vn;i++)
        {
            row[i] = a.row[i];
            col[i] = a.col[i];
            val[i] = a.val[i];
        }
    }

    SparseMatrix(int _rn, int _cn, int _maxSize)
    {
        // 开一个_rn*_cn的空矩阵
        // 后续最多_maxSize个非零元素
        maxSize = _maxSize;
        rn = _rn;
        cn = _cn;
        vn = 0; // 这个是故意的，因为都是0元素
        row = new int[maxSize+1];
        col = new int[maxSize+1];
        val = new int[maxSize+1];
    }

    SparseMatrix(int _rn, int _cn, int _vn, int _row[], int _col[], int _val[])
    {
        maxSize = _vn;
        rn = _rn;
        cn = _cn;
        vn = _vn;
        row = new int[vn+1];
        col = new int[vn+1];
        val = new int[vn+1];
        for (int i=1;i<=vn;i++)
        {
            row[i] = _row[i];
            col[i] = _col[i];
            val[i] = _val[i];
        }
    }

    ~SparseMatrix()
    {
        delete [] row;
        delete [] col;
        delete [] val;
    }

    SparseMatrix transpose() // 在这里实现转置
    {
        SparseMatrix res(cn,rn,vn); // 注意最后一个元素是maxSize，vn要手动设置一下
        int* num = new int[cn+1];
        int* cpot = new int[cn+1];

        // num[j] 统计原矩阵第 j 列的非零元素个数。
        for (int j = 0; j <= cn; ++j)
            num[j] = 0;
        for (int i = 1; i <= vn; ++i)
            ++num[col[i]];

        // cpot[j] 是转置后第 j 行下一个元素应存放的位置。
        int next = 1;
        for (int j = 1; j <= cn; ++j)
        {
            cpot[j] = next;
            next += num[j];
        }
        for (int i = 1; i <= vn; ++i)
        {
            int pos = cpot[col[i]]++;
            res.row[pos] = col[i];
            res.col[pos] = row[i];
            res.val[pos] = val[i];
        }
        res.vn = vn;

        delete [] num;
        delete [] cpot;
        return res;
    }
    
    int at(const int x, const int y) // 返回x行，y列的元素
    {
        // 未存储的位置就是零元素，三元组下标从 1 开始。
        for (int i = 1; i <= vn; ++i)
        {
            if (row[i] == x && col[i] == y)
                return val[i];
        }

        return 0;
    }
    
    /*
        这就是上次提到的重载运算符
        用起来就是 c = a+b;
        跟c = a.add(b);是一个效果
        
        你实现的代码跟下面这个函数是完全一样的。
        SparseMatrix add(const SparseMatrix& b)

        测试保证相加的矩阵有相同的形状
        提示：就是合并两个有序序列
        提示：有可能两个元素相加之后变为0
     */
    SparseMatrix operator+(const SparseMatrix& b)
    {
        /*
            row, col, val 就是加号前面那个矩阵的成员
            b.row, b.col, b.val 就是加号后面那个矩阵的成员
        */

        // 两个矩阵相加，非零元素最多不会超过两个矩阵非零元素个数之和。
        SparseMatrix res(rn,cn,vn+b.vn);

        // 有了下面这行，你就可以用a.row代替row写代码了
        // 这样感觉和b.row什么的长得很像。可能有助于减少你的bug
        // 当然你不喜欢的话就把下面这行删掉就行
        SparseMatrix &a = (*this);

        int i = 1;
        int j = 1;
        // 输入三元组按行优先排列，同时向前扫描两个序列。
        while (i <= a.vn || j <= b.vn)
        {
            int r, c, value;
            if (j > b.vn || (i <= a.vn &&
                (a.row[i] < b.row[j] ||
                 (a.row[i] == b.row[j] && a.col[i] < b.col[j]))))
            {
                r = a.row[i];
                c = a.col[i];
                value = a.val[i];
                ++i;
            }
            else if (i > a.vn || b.row[j] < a.row[i] ||
                     (b.row[j] == a.row[i] && b.col[j] < a.col[i]))
            {
                r = b.row[j];
                c = b.col[j];
                value = b.val[j];
                ++j;
            }
            else
            {
                r = a.row[i];
                c = a.col[i];
                value = a.val[i] + b.val[j];
                ++i;
                ++j;
            }

            // 相同位置的值可能互相抵消，结果中只存非零元素。
            if (value != 0)
            {
                ++res.vn;
                res.row[res.vn] = r;
                res.col[res.vn] = c;
                res.val[res.vn] = value;
            }
        }


        return res;
    }
};

#endif