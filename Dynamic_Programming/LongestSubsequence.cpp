#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;


/*
 * solve(idx, prev_idx) -> length of longest subsequence from nums[idx..n-1] such that prev_idx is the previous element
 *
*/
int solve(vector<int>& nums, vector<vector<int>>& dp, int idx, int prev_idx){
  if( idx >= nums.size() ) return 0;

  if( dp[idx][prev_idx + 1] != -1 ) return dp[idx][prev_idx+1];

  int not_take = 0 + solve(nums,dp,idx+1,prev_idx);
  int take = INT_MIN;

  if( prev_idx == -1 || nums[idx] > nums[prev_idx] ){
    take = 1 + solve(nums,dp,idx+1,idx);
  }

  return dp[idx][prev_idx+1] = max(take,not_take);

}

int longestIncreasingSubsequence(vector<int>& nums, int memo){
  int n = nums.size();
  if( memo ){
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

    return solve(nums,dp,0,-1);
  }

  vector<int> dp(n,1); // dp[i] = length of longest increasing subsequence such that the last element is nums[i]

  for(int i=1; i<n; i++){
    for(int j=0; j<i; j++){
      if( nums[j] < nums[i] && dp[j] + 1 > dp[i] ){
        dp[i] = dp[j] + 1;
      }
    }
  }
  
  return *max_element(dp.begin(),dp.end());
}
int main(){
  vector<int> nums{2,1,1,4,2,5,3,6,10,8,9};
  cout<<longestIncreasingSubsequence(nums,1)<<endl;
  cout<<longestIncreasingSubsequence(nums, 0)<<endl;
}
