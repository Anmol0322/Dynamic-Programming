#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int dp[10010];

int func(vector<int>& coins, int amount){
	if(amount == 0) return 0;
	if(dp[amount] != -1) return dp[amount];
	int ans = INT_MAX;
	for(int coin=0;coin < coins.size(); coin++){
		if(amount - coins[coin] >= 0){
			ans = min(ans+0LL, func(coins, amount - coins[coin]) + 1LL);
		}
	}
	return dp[amount] = ans;
}

int coinChange(vector<int>& coins, int amount) {
	memset(dp,-1,sizeof(dp));
    int ans = func(coins, amount);
    return ans == INT_MAX ? -1 : ans;
}

int main(){
	vector<int> coins;
	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(5);
	int amount = 11;
	cout << coinChange(coins, amount);
}
