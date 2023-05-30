#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
typedef vector<vector<pair<int, int>>> table;
class Solution {
public:
  int splitArray(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      prefix[i] = prefix[i - 1] + nums[i - 1];
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return solve(1, k, prefix, dp);
  }

  int solve(int i, int k, vector<int> &prefix, vector<vector<int>> &dp) {
    int n = prefix.size();
    if (k == 1) {
      return prefix[n - 1] - prefix[i - 1];
    }

    if (dp[i][k] != -1)
      return dp[i][k];
    int minVal = INT_MAX;
    for (int j = i; j <= n - k; j++) {
      int a = prefix[j] - prefix[i - 1];
      int b = solve(j + 1, k - 1, prefix, dp);
      minVal = min(minVal, max(a, b));
    }

    return dp[i][k] = minVal;
  }
};
