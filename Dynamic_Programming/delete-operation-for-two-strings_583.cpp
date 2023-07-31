/*

"sea"
"eat";

"leetcode"
"etco";

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[501][501];
    int minDistance(string& s1, string& s2)
    {
        memset(dp,-1,sizeof(dp));
        return solve(s1, s2, s1.length() - 1, s2.length() - 1);
    }

    int solve(string& s1, string& s2, int i, int j)
    {
        if (i < 0 && j < 0) {
            return 0;
        }
        if (i < 0) {
            return j + 1;
        }
        if (j < 0) {
            return i + 1;
        }

        if( dp[i][j] != -1 ) return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i - 1, j - 1);
        }
        return dp[i][j] = 1 + min(solve(s1, s2, i - 1, j), solve(s1, s2, i, j - 1));
    }
};
