class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n,vector<int>(n,1e7));
        for(int j=0; j<n; j++){
            dp[0][j] = grid[0][j];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(k==j) continue;
                    dp[i][j] = min(dp[i][j],dp[i-1][k] + grid[i][j]);
                }
            }
        }

        int minAns = 1e9;
        for(int i=0; i<n; i++){
            minAns = min(minAns,dp[n-1][i]);
        }

        return minAns;
    }
};
