#include<bits/stdc++.h>
using namespace std;
const int N = 25e2+10;
int dp[N];
int ar[] = {10,9,2,5,3,7,101,18};

int lis(int i){
	if(dp[i] != -1) return dp[i];
	int ans = 1;
	for(int j=0;j<i;j++){
		if(ar[i]>ar[j])
		ans = max(ans, lis(j) + 1);
	}
	return dp[i] = ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	int ans = 0;
	for(int i=0;i<8;i++){
		ans = max(ans,lis(i));//checking for every number 
	}
	cout << ans;
	return 0;
}
