/*

"tbgtgb";

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[101][101];
    int strangePrinter(string& s)
    {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, s.length() - 1);
    }

    int solve(string& s, int i, int j)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int result = solve(s, i, j - 1) + 1;

        for (int k = i; k < j; k++) {
            if (s[k] == s[j]) {
                result = min(result, solve(s, i, k) + solve(s, k + 1, j - 1));
            }
        }
        return dp[i][j] = result;
    }
};
