#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> dp(n+1,vector<long long>(k+1,-1));
        vector<long long> vec(n);
        vec[0] = nums[0];
        for(int i=1; i<n; i++){
            vec[i] = vec[i-1] | nums[i];
        }
        return solve(n-1,k,nums,dp,vec);
    }
    long long solve(int i, int k, vector<int>& nums,vector<vector<long long>>& dp, vector<long long>& vec){
        if(i < 0) return 0;
        if( dp[i][k] != -1 ) return dp[i][k];
        if(k == 0){
            long long ans = 0;
            return vec[i];
            for(int j=0; j<=i; j++){
                ans |= nums[j];
            }
            return ans;
        }
        
        long long ans = 0;
        for(int u=0; u<=k; u++){
            ans = max(ans, (long long)(nums[i]*pow(2,u)) | solve(i-1,k-u,nums,dp,vec));
        }
        
        return dp[i][k] = ans;
    }
};
