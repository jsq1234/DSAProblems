#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int dp[1000001][4];
  int countTriplets(vector<int> &nums) {
    int n = nums.size();
    // memset(dp,-1,sizeof(dp));
    map<pair<int, int>, int> dp;
    return solve(nums, INT_MAX, dp, 3);
  }
  int solve(vector<int> &nums, int val, map<pair<int, int>, int> &dp, int k) {

    if (k == 0 && val == 0)
      return 1;
    if (k == 0)
      return 0;
    // if( dp[val][k] != -1 ) return dp[val][k];
    if (dp.find({val, k}) != dp.end()) {
      pair<int, int> p = {val, k};
      return dp[p];
    }
    int ways = 0;
    for (int i = 0; i < nums.size(); i++) {
      ways += solve(nums, val & nums[i], dp, k - 1);
    }
    pair<int, int> p = {val, k};
    return dp[p] = ways;
  }
};
