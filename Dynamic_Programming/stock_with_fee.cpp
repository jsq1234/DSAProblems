#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[5*(size_t)1e4+1][2];
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,fee,0,0);
    }
    int solve(vector<int>& prices, int fee, int buy, int i){
        if( i >= prices.size() ){
            return 0;
        }

        if( dp[i][buy] != -1 ) return dp[i][buy];

        int max_profit = INT_MIN;

        if(buy){
            // sell or not sell
            int sell = prices[i] - fee + solve(prices,fee,!buy,i+1);
            int not_sell = solve(prices,fee,buy,i+1);

            max_profit = max(sell,not_sell);
        }else{
            int but = -prices[i] + solve(prices,fee,!buy,i+1);
            int not_buy = solve(prices,fee,buy,i+1);

            max_profit = max(but,not_buy);
        }

        return dp[i][buy] = max_profit;
    }
};
