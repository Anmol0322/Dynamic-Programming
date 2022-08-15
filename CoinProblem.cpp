#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int dp[310][10010];

//int func(vector<int>& coins, int amount){
//	if(amount == 0) return 1;
//	if(dp[amount] != -1) return dp[amount];
//	int ways = 0;
//	for(int coin=0;coin < coins.size(); coin++){
//		if(amount - coins[coin] >= 0){
//			ways += func(coins, amount - coins[coin]);
//		}
//	}
//	return dp[amount] = ways;
//}
//Wrong, bcs it counts all the different ways 

int func1(int index, vector<int>& coins, int amount){
	if(amount == 0) return 1;
	if(index < 0) return 0;
	if(dp[index][amount] != -1) return dp[index][amount];
	int ways = 0;
	for(int coin_amount=0;coin_amount <=amount; coin_amount+=coins[index]){
		ways += func1(index - 1, coins, amount - coin_amount);
	}
	return dp[index][amount] = ways;
}

int coinChange(vector<int>& coins, int amount) {
	memset(dp,-1,sizeof(dp));
    int ways = func1(coins.size() - 1, coins, amount);
    return ways;
}

int main(){
	vector<int> coins;
	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(5);
	int amount = 5;
	cout << coinChange(coins, amount);
}
