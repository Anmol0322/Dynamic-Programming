#include<bits/stdc++.h>
using namespace std;

void totalPrimes(int n){
	vector<int> dp(n+1,true);
	for(int i=2;i<=n;i++){
		if(dp[i]){
			cout << i ;
			for(int j=i*i;j<=n;j+=i){
				dp[j]=false;	
			}
		}
	}	
}

int main(){
	int n=10;
	totalPrimes(n);
	return 0;
}
