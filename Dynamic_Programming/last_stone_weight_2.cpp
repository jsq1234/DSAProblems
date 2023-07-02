#include <bits/stdc++.h>
#include <numeric>
using namespace std;

class Solution {
public:
    int dp[31][3001];
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        int n = stones.size();
        int sum = accumulate(stones.begin(),stones.end(),0);

        int val = func(stones,n-1,sum/2);

        return sum - 2*val;
    }

    int func(vector<int>& stones, int i, int target){
        if( i < 0 || target == 0 ) return 0;

        if( dp[i][target] != -1 ) return dp[i][target];

        int take = 0, not_take = 0;

        if( target - stones[i] >= 0 )
            take = stones[i] + func(stones,i-1,target - stones[i]);
        not_take = func(stones,i-1,target);

        return dp[i][target] = max(take,not_take);
    }
};