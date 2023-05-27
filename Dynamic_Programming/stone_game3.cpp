#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dp[100001];
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int sum = accumulate(stoneValue.begin(),stoneValue.end(),0);
        memset(dp,-1,sizeof(dp));
        int score1 = f(stoneValue,0);
        int alice_score = (sum + score1)/2;
        int bob_score = (sum - alice_score);
        
        if( alice_score == bob_score ) return "Tie";
        
        return alice_score > bob_score ? "Alice" : "Bob";
    }

    int f(vector<int>& st, int i){
        if( i >= st.size() ) return 0;
        if( dp[i] != -1 ) return dp[i];

        int taken = 0, res = INT_MIN;

        for(int j=0; j<3; j++){
            int idx = i + j;
            if( idx >= st.size() ) break;
            taken += st[idx];
            res = max(res, taken - f(st,idx+1));
        }

        return dp[i] = res;
    }
};
