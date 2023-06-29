#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> dict;
        for(string& str : wordDict) dict.insert(str);
        vector<int> dp(n,-1);
        return solve(s,0,dict,dp);
    }
    bool solve(string& s, int j, unordered_set<string>& dict,vector<int>& dp){
        if( j >= s.length() ) return false;
        if( dp[j] != - 1) return dp[j];

        bool ans = false;
        for(int k=j; k<s.length(); k++){
            string prefix = s.substr(j,k-j+1);
            if( dict.find(prefix) != dict.end() ){
                ans |= solve(s,k+1,dict,dp);
            }
        }

        return dp[j] = (ans || dict.find(s.substr(j)) != dict.end()) ;
    }
};
