#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int wiggleMaxLength(vector<int>& nums) {
  int n = nums.size();
  vector<int> dp(n,1);
  vector<int> prev(n,-1); // diff of previous element, 1 -> positive, 0 -> negative, -1 -> any 

  for(int i=1; i<n; i++){
    for(int j=0; j<i; j++){
      if( dp[j] + 1 <= dp[i] ){
        continue;
      }
      if( prev[j] == -1 ){
        if(nums[i] == nums[j]) continue;
        prev[i] = nums[i] > nums[j];
      }
      else if(nums[i] < nums[j] && prev[j]) {
        prev[i] = 0;
      }
      else if(nums[i] >= nums[j] && !prev[j]){
        prev[i] = 1;
      }else{
        continue;
      }
      dp[i] = dp[j]+1;

    }
  }

  int idx = max_element(dp.begin(),dp.end()) - dp.begin();
  return dp[idx];
}

int main(){
  vector<int> nums{1,17,5,10,13,15,10,5,16,8};
  cout<<wiggleMaxLength(nums)<<endl;
}
