/*

[[-2,-3,3],[-5,-10,1],[10,30,-5]];

[[0]];

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int dp[201][201];

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
       int n = dungeon.size();
       int m = dungeon[0].size();
       memset(dp,-1,sizeof(dp));
       return solve(dungeon,0,0,n,m);
    }

    int solve(vector<vector<int>>& dungeon, int i, int j, int n, int m){
        if( i>=n || j >= m ) return 1e7;
        if( i == n-1 && j == m-1 ) return max(1,-dungeon[i][j]+1);
        if( dp[i][j] != -1 ) return dp[i][j];
        int ans = min(solve(dungeon,i+1,j,n,m),solve(dungeon,i,j+1,n,m)) - dungeon[i][j];
        return dp[i][j] = (ans <= 0) ? 1 : ans;
    }
};
