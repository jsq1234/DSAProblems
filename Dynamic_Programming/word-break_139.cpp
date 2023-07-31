/*

"leetcode"
["leet","code"];

"applepenapple"
["apple","pen"];

"catsandog"
["cats","dog","sand","and","cat"];

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[301];
    bool wordBreak(string& s, vector<string>& wordDict)
    {
        memset(dp,-1,sizeof(dp));
        unordered_set<string> st;
        for (string& str : wordDict) { 
            st.insert(str);
        }

        return solve(s,0,st);
    }
    bool solve(string& s, int i, unordered_set<string> wordDict)
    {
        int n = s.length();

        if( i >= n ) return true;

        if( dp[i] != -1 ) return dp[i];

        string str = "";

        for(int k=i; k<n; k++){
            str += s[k];
            if(wordDict.find(str) != wordDict.end()){
                bool a = solve(s,k+1,wordDict);
                if(a){
                    return dp[i] = true;
                }
            }
        }

        return dp[i] = false;
    }
};
