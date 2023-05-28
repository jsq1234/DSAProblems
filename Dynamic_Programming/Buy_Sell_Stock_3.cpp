#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

#define BUY 0
#define SELL 1
class Solution {
public:
    int dp[100001][3][2];
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vector<vector<int>> dp(n,vector<int>(2,0));
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,2,0);
    }
    int solve(vector<int>& prices, int i, int k, int buy){
        if(i >= prices.size()) return 0;
        if( dp[i][k][buy] != -1 ) return dp[i][k][buy];
        if( k == 0 ) return 0;

        if(buy){
            return dp[i][k][buy] = max(prices[i] + solve(prices,i+1,k-1,!buy),
                    solve(prices,i+1,k,buy));
        }
        return dp[i][k][buy] = max(-prices[i] + solve(prices,i+1,k,!buy),
                solve(prices,i+1,k,buy));
    }
};
