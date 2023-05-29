#include <algorithm>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
  int dp[501][501];
  int maxSatisfaction(vector<int> &sat) {
    int n = sat.size();
    sort(sat.begin(), sat.end(), [](int x, int y) { return x > y; });
    memset(dp, -1, sizeof(dp));
    return solve(sat, 1, n - 1);
  }
  int solve(vector<int> &sat, int time, int idx) {
    if (idx < 0)
      return 0;
    if (dp[idx][time] != -1)
      return dp[idx][time];
    int pick = time * sat[idx] + solve(sat, time + 1, idx - 1);
    int not_pick = solve(sat, time, idx - 1);

    return dp[idx][time] = max(pick, not_pick);
  }
};
