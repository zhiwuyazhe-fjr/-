#include "SparseMatrixB.hpp"
#include <iostream>
using namespace std;
int row[1000];
int col[1000];
int val[1000];
// 打印矩阵，同时测试at函数
void printMatrix(SparseMatrix & a)
{
    for (int i=1;i<=a.rn;i++)
    {
        for (int j=1;j<=a.cn;j++)
        {
            cout<<a.at(i,j)<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    int rn,cn,vn;
    // 矩阵a
    cin>>rn>>cn>>vn;
    for (int i=1;i<=vn;i++)
        cin>>row[i]>>col[i]>>val[i];
    SparseMatrix a(rn,cn,vn,row,col,val);
    printMatrix(a);
    // 矩阵b
    cin>>rn>>cn>>vn;
    for (int i=1;i<=vn;i++)
        cin>>row[i]>>col[i]>>val[i];
    SparseMatrix b(rn,cn,vn,row,col,val);
    printMatrix(b);
    // 测试转置
    SparseMatrix c = a.transpose();
    printMatrix(c);
    // 测试加法
    SparseMatrix d = b+c;
    printMatrix(d);
    return 0;
}