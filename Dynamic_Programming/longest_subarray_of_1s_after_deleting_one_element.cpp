#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
        int dp[(size_t)1e5+1][2];
        int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        int one_count = 0;
        for_each(nums.begin(),nums.end(),[&](int x) {
            one_count += x == 1;
        });

        if( one_count == n ) return n-1;

        for(int i=0; i<n; i++){
            ans = max(ans, func(nums,i,0));
        }

        return ans;
    }

    // func(nums,i,k) -> the length of largest subarray that ends 
    // at idx = i with k deletions
    int func(vector<int>& nums, int i, int k){
        if( i < 0 ) return 0;

        if( dp[i][k] != -1 ) return dp[i][k];

        if( k == 0 ){
            int not_deleted = nums[i] == 0 ? 0 : func(nums,i-1,k) + 1;
            int deleted = func(nums,i-1,k+1);
            return dp[i][k] = max(not_deleted,deleted);
        }else{
            return dp[i][k] = nums[i] == 0 ? 0 : func(nums,i-1,k) + 1;
        }
    }

};
