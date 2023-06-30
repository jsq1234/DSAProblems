#include <bits/stdc++.h>
using namespace std;

class Solution {
  int dp[21][31];

  bool solve(string &s, string &p, int sp, int pp) {
    if (dp[sp][pp] != -1) {
      return dp[sp][pp];
    }

    int ans = 0;
    if (pp == 0) {
      ans = sp == 0;
    } else if (sp == 0) {
      int i = pp;
      while (i >= 1 && p[i - 1] == '*') {
        i -= 2;
      }
      ans = i == 0;
    } else if (p[pp - 1] == '*') {
      char wildcard = p[pp - 2];

      int i = sp;
      for (; i >= 1 && (wildcard == '.' || s[i - 1] == wildcard); --i) {
        ans = solve(s, p, i, pp - 2);
        if (ans) {
          break;
        }
      }
      if (!ans) {
        ans = solve(s, p, i, pp - 2);
      }
    } else if (p[pp - 1] == '.' || p[pp - 1] == s[sp - 1]) {
      ans = solve(s, p, sp - 1, pp - 1);
    }

    dp[sp][pp] = ans;
    return ans;
  }

public:
  bool isMatch(string s, string p) {
    memset(dp, -1, sizeof(dp));
    dp[0][0] = true;
    return solve(s, p, s.size(), p.size());
  }
};