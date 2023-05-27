#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int dp[101];
    int numDecodings(string s) {
        int n = s.length();
        if( s[0] == '0' ) return 0;
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
    }
    int solve(int i, string& s){
        if( i >= s.length() ) return 1;
        if( dp[i] != -1 ) return dp[i];
        if( i == s.length() - 1 ) return s[i] != '0';
        if( s[i] == '0' ) return dp[i] = 0;
        int t = stoi(s.substr(i,2));
        if( t > 26 &&  s[i+1] != '0' ) return dp[i] = solve(i+1,s);
        if( t > 26 && s[i+1] == '0' ) return dp[i] = 0;
        if( t <= 26 && s[i+1] != '0' ) return dp[i] = solve(i+1,s) + solve(i+2,s);
        if( t <= 26 && s[i+1] == '0' ) return dp[i] = solve(i+2,s);
        return 0;
    }
};


