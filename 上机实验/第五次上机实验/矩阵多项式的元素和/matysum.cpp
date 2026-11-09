#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCount;
    if (!(cin >> testCount))
        return 0;

    vector<int> queries(testCount);
    int maxN = 0;
    for (int i = 0; i < testCount; ++i)
    {
        cin >> queries[i];
        maxN = max(maxN, queries[i]);
    }

    // A 严格下三角，因此 A^n = 0，且 B = A + A*B。
    // 设 s[i] 为 B 的第 i 行元素和，则
    // s[i] = sum_{j | i, j < i} i*j*j*(1+s[j])。
    // 所有真约数 j 都小于 i，可以从小到大计算并向倍数传播贡献。
    vector<int> rowSum(maxN + 1, 0);
    for (int divisor = 1; divisor <= maxN / 2; ++divisor)
    {
        long long weight = 1LL * divisor * divisor % MOD;
        weight = weight * (rowSum[divisor] + 1LL) % MOD;
        for (int multiple = divisor * 2; multiple <= maxN; multiple += divisor)
        {
            int contribution = static_cast<int>(weight * multiple % MOD);
            rowSum[multiple] += contribution;
            if (rowSum[multiple] >= MOD)
                rowSum[multiple] -= MOD;
        }
    }

    // 第 i 行只依赖编号更小的行，扩展矩阵大小不会改变已有行的答案。
    // 原地改为前缀和后，rowSum[n] 就是 n x n 矩阵 B 的所有元素和。
    for (int i = 1; i <= maxN; ++i)
    {
        rowSum[i] += rowSum[i - 1];
        if (rowSum[i] >= MOD)
            rowSum[i] -= MOD;
    }
    for (int i = 0; i < testCount; ++i)
        cout << rowSum[queries[i]] << '\n';

    return 0;
}
