#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* number of longest increasing subsequences
*/

int longestSubsequence(vector<int>& nums){
  // dp[i][j] -> number of subsequences that end at nums[i] and has length l;
  int n = nums.size();
  vector<int> dp(n,1);
  vector<int> count(n+1,0);
  // count[i] - > number of lis such that they end at nums[i]
  for(int i=1; i<n; i++){
    for(int j=0; j<i; j++){
      if( nums[j] < nums[i] ){
        if(dp[j] + 1 > dp[i]){
          dp[i] = dp[j] + 1;
          count[i] = count[j];
        }
        else if(dp[j] + 1 == dp[i]){
          count[i] += count[j];
        }
      }
    }
  }

  int len = *max_element(dp.begin(),dp.end());
  
  int max_count = 0;
  for(int i=0; i<n; i++){
    if(dp[i] == len){
      max_count += count[i];
    }
  }
  return max_count;
}

int main(){

}
