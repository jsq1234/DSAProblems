/*

[[0,1,-1],[1,0,-1],[1,1,1]];

[[1,1,-1],[1,-1,1],[-1,1,1]];

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[51][51][51];
    int cherryPickup(vector<vector<int>>& grid)
    {
        memset(dp,-1,sizeof(dp));
        int ans = fun(0,0,0,grid.size(),grid);
        return max(ans,0);
    }
    int fun(int r1, int r2, int c1, int n, vector<vector<int>>& grid)
    {
        int c2 = r1 - r2 + c1;
        if( r1 >= n || r2 >= n || c1 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1 ){
            return -1e6;
        }
        if (dp[r1][r2][c1] != -1)
            return dp[r1][r2][c1];
        if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];

        int temp = 0;
        if (r1 == r2 && c1 == c2) {
            temp += grid[r1][c1];
        } else {
            temp += grid[r1][c1] + grid[r2][c2];
        }

        int a = fun(r1+1,r2+1,c1,n,grid);
        int b = fun(r1,r2,c1+1,n,grid);
        int c = fun(r1,r2+1,c1+1,n,grid);
        int d = fun(r1+1,r2,c1,n,grid);

        temp += max({a,b,c,d});
        return dp[r1][r2][c1] = temp;
    }

};
