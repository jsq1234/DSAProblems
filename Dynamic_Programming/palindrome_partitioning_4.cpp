class Solution {
public:
    bool checkPartitioning(string& s) {
        int n = s.length();
        vector<int> memo(n,-1);
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
        }
        for(int i=0; i<n-1; i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = 1;
            }
        }
        for(int len=3; len<=n; len++){
            for(int i=0; i<=n-len; i++){
                int j = i+len-1;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = 1;
                }
            }
        }

        return solve(dp,memo,0,n,3);
    }

    bool solve(vector<vector<int>>& dp,vector<int>& memo, int i, int n, int k){
        if( i >= n && k == 0 ) return true;
        if( i >= n || k == 0 ) return false;

        if( k == 1 ) return dp[i][n-1];
        
        bool ans = false;
        for(int j=i; j<n; j++){
            if(dp[i][j]){
                if(solve(dp,memo,j+1,n,k-1)) return memo[i] = true;
            }
        }
        return memo[i] = false;
    }
};
