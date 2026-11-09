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
        vn = 0;
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
        SparseMatrix res(cn,rn,vn);
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
};
#endif