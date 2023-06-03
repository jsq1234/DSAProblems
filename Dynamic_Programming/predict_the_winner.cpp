#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int dp[21][21];
    bool PredictTheWinner(vector<int>& nums) {
            int n = nums.size();
            memset(dp,-1,sizeof(dp));
            int p1 = play(nums,0,n-1);
            int sum = accumulate(nums.begin(), nums.end(),0);
            int p2 = sum - p1;
            return p1 >= p2;
        }
    int play(vector<int>& nums, int i, int j){
            if( i == j  ) return nums[i];
            if( j - i == 1  ) return max(nums[i],nums[j]);
            if( i > j  ) return 0;
            if( dp[i][j] != -1  ) return dp[i][j];
    
            int first = nums[i] + min(play(nums,i+2,j),play(nums,i+1,j-1));
            int last = nums[j] + min(play(nums,i,j-2),play(nums,i+1,j-1));
    
            return dp[i][j] = max(first,last);
        }
};
