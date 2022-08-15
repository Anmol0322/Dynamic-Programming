#include<bits/stdc++.h>
using namespace std;
const int N = 10e5+10;
int dp[N];
int k;
int h[] = {10,30,40,50,20};

int func(int i){
	if(i==0) return 0;
	int cost = INT_MAX;
	if(dp[i] != -1) return dp[i];
	for(int j=1;j<=k;j++){
		if(i-j >= 0)
			cost = min(cost, func(i-j) + abs(h[i] - h[i-j]));
	}
	return dp[i]=cost; 
}

int main(){
	memset(dp,-1,sizeof(dp));
	int n = 5;
	k = 3;
	cout<<func(n-1);
}

//TC: O(n*k)
