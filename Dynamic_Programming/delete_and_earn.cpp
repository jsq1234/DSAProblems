#include <bits/stdc++.h>
using namespace std;

// very similar to House Robber
//
class Solution {

public:
    int dp[100001];
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
        return solve(nums,n-1);
        
    }
    int deleteAndEarn_Tabulation(vector<int>& nums){
        int n = nums.size();
        int m = *max_element(nums.begin(),nums.end());
        vector<int> count(m+1,0);
        
        for(int x : nums) count[x] += x;
        
        for(int i=2; i<=m; i++){
          count[i] = max(count[i] + count[i-2], count[i]);
        }
        
        return count[m];
  }
    int solve(vector<int>& nums, int i){
        if( i < 0 ) return 0;
        if( dp[i] != -1 ) return dp[i];
        int j = i, sum = 0;
        while(j >= 0 && (nums[j] == nums[i])){
            sum += nums[j];
            j--;
        }
        int idx = j;
        int dec = nums[i] - 1;
        while(idx >= 0 && (nums[idx] == dec)) idx--;

        int take = sum + solve(nums,idx);
        int nottake = solve(nums,j);

        return dp[i] = max(take,nottake);
    }
};
