#include <bits/stdc++.h>
using namespace std;

struct my_pair{
    int cost;
    int time;
};
class Solution {
public:
    int dp[501][501];
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        memset(dp,-1,sizeof(dp));
        return solve(cost,time,0,n);
    }
    
    int solve(vector<int>& cost, vector<int>& time, int i, int w){
        if( w <= 0 ) return 0;
        if( i >= cost.size() ) return INT_MAX;

        if( dp[i][w] != -1 ) return dp[i][w];

        int notpick = solve(cost,time,i+1,w);
        int r = solve(cost,time,i+1,w-time[i]-1);
        if(r == INT_MAX){
            return dp[i][w] = notpick;
        }
        int pick = cost[i] + solve(cost,time,i+1,w-time[i]-1);
        
        return dp[i][w] = min(pick,notpick);
    }
};
