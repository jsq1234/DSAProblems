#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Solution {
public:
  int dp[20][4001];
  int findTargetSumWays(vector<int> &nums, int target) {
    int n = nums.size();
    memset(dp, -1, sizeof(dp));
    return solve(nums, target, n - 1);
  }
  int solve(vector<int> &nums, int target, int i) {
    if (target == 0 && i < 0)
      return 1;
    if (i < 0)
      return 0;
    if (dp[i][target + 2000] != -1)
      return dp[i][target + 2000];
    return dp[i][target + 2000] = solve(nums, target - nums[i], i - 1) +
                                  solve(nums, target + nums[i], i - 1);
  }
};
