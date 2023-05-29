#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
  const int m = 1e9 + 7;
  int dp[101][101][101];
  int profitableSchemes(int n, int minProfit, vector<int> &group,
                        vector<int> &profit) {
    int idx = group.size() - 1;
    memset(dp, -1, sizeof(dp));
    return f(n, idx, minProfit, 0, group, profit);
  }
  int f(int n, int i, int mp, int cp, vector<int> &group, vector<int> &profit) {
    if (i < 0) {
      return cp >= mp;
    }

    if (dp[i][cp][n] != -1)
      return dp[i][cp][n];

    int commit = 0;
    if (n >= group[i]) {
      commit =
          f(n - group[i], i - 1, mp, min(mp, cp + profit[i]), group, profit) %
          m;
    }
    // int commit = f(n-group[i], i-1, mp, cp + profit[i], group, profit)%m;
    int not_commit = f(n, i - 1, mp, cp, group, profit) % m;

    return dp[i][cp][n] = (commit % m + not_commit % m) % m;
  }
};
