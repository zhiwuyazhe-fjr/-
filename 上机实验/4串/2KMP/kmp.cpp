#include <iostream>
#include <string.h>
using namespace std;
const int SIZE_N = 1e5+10;
const int SIZE_M = 1e3+10;
int N,M, ans;
int nxt[SIZE_M];
char a[SIZE_M];
/**
 * @brief Solution to the Question
 *  - HINT: kmp
 */
void solve(){
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
