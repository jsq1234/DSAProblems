#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9+7;
    int dp[1001][1001];
    int d1[4] = { 1, 0, -1, 0 };
    int d2[4] = { 0, -1, 0, 1 };
    int countPaths(vector<vector<int>>& grid) {
        
        memset(dp,-1,sizeof(dp));
        int n = grid.size();
        int m = grid[0].size();

        long long total = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                total = (total%mod + solve1(grid,i,j,n,m)%mod)%mod;
            }
        }
        return total;
    }

    int check(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int solve1(vector<vector<int>>& grid, int i, int j, int n, int m){
        if( dp[i][j] != -1 ) return dp[i][j];
        int paths = 1;

        for(int k=0; k<4; k++){
            int r = i + d1[k];
            int c = j + d2[k];

            if(check(r,c,n,m) && grid[r][c] > grid[i][j]){
                paths = (paths%mod + solve1(grid,r,c,n,m)%mod)%mod;
            }
        }

        return dp[i][j] = paths;

    }
};
