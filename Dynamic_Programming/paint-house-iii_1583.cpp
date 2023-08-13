/*

[0,0,0,0,0]
[[1,10],[10,1],[10,1],[1,10],[5,1]]
5
2
3;

[0,2,1,2,0]
[[1,10],[10,1],[10,1],[1,10],[5,1]]
5
2
3;

[3,1,2,3]
[[1,1,1],[1,1,1],[1,1,1],[1,1,1]]
4
3
3;

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[101][21][101];
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target)
    {
        memset(dp,-1,sizeof(dp));
        int ans = solve(houses,cost,0,0,target);
        return ans == 1e7 ? -1 : ans;
    }
    int solve(vector<int>& houses, vector<vector<int>>& cost, int idx, int prevColor, int target){

        if((idx >= houses.size() && target != 0) || target < 0) return 1e7;
        if(idx >= houses.size() && target == 0) return 0;

        int& ref = dp[idx][prevColor][target];
        
        if(ref != -1) return ref;

        if(houses[idx] != 0){
            if(houses[idx] == prevColor){
                return ref = solve(houses,cost,idx+1,houses[idx],target);
            }else{
                return ref = solve(houses,cost,idx+1,houses[idx],target-1);
            }
        }

        int ans = 1e7;
        for(int j=0; j<cost[idx].size(); j++){
            int cc = cost[idx][j];
            int temp = solve(houses,cost,idx+1,j+1,target - 1*(j+1 != prevColor));
            ans = min(ans, temp + cc);
        }

        return ref = ans;

    }
};
