#include <iostream>
#include <string.h>
using namespace std;
const int SIZE_N = 1e5+10;
const int SIZE_M = 1e7+10;
int N,M, ans;
int nxt[SIZE_M];
char a[SIZE_M];
/**
 * @brief Solution to the Question
 *  - HINT: kmp
 */
void solve(){
	M = strlen(a + 1);
	for (int i = 2, j = 0; i <= M; ++i) {
		// 失配时，尝试当前已匹配部分更短的相同前后缀。
		while (j > 0 && a[i] != a[j + 1]) {
			j = nxt[j];
		}
		if (a[i] == a[j + 1]) {
			++j;
		}
		nxt[i] = j;
	}
	// 允许最后一段不完整，最短循环节不必整除字符串长度。
	ans = M - nxt[M];
}
/**
 * @brief Obtain Input
 */
void in(){
	scanf("%s",(a+1));
}
void init(){
	memset(nxt, 0, sizeof(nxt));
	memset(a, 0, sizeof(a));
	M = ans = 0;
}
int main(){
	scanf("%d",&N);
	while(N--){
		init();
		in();
		solve();
		printf("%d\n",ans);
	}
	return 0;
}
