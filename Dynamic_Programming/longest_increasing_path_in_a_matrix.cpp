#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int d1[4] = { 0, 1, 0, -1 };
    int d2[4] = { 1, 0, -1, 0 };
    int dp[201][201];
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));

        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = max(ans, solve(matrix,i,j, n,m));
            }
        }

        return ans;

    }
    int check(int i, int j, int n, int m){
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    int solve(vector<vector<int>>& mat, int i, int j, int n, int m){
        if( dp[i][j] != -1 ){
            return dp[i][j];
        }

        int ans = 1;

        for(int k=0; k<4; k++){
            int r = i + d1[k];
            int c = j + d2[k];
            if( check(r,c,n,m) && mat[r][c] > mat[i][j] ){
                ans = max(ans, 1 + solve(mat,r,c,n,m));
            }
        }

        return dp[i][j] = ans;
    }
};
