#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
  
    int dp[2001];
    int minCut(string& s) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));

        vector<vector<int>> arr(n,vector<int>(n,0));
        for(int i=0; i<n; i++){
            arr[i][i] = 1;
        }

        

        for(int len=2; len<=n; len++){
            for(int i=0; i<=n-len; i++){
                int j = i + len - 1;
                if( s[i] == s[j] && ( len == 2 || arr[i+1][j-1]) ){
                    arr[i][j] = 1;
                }
            }
        }

    
        return func(s,arr,0);
    }

    int func(string& s, vector<vector<int>>& is_palindrome, int i){
        int n = s.length();

        if( i == n ) return 0;
        if( is_palindrome[i][n-1] ) return 0;
        if( dp[i] != -1 ) return dp[i];

        int min_ans = 1e7;
        for(int m=i; m<n-1; m++){
            if(is_palindrome[i][m]){
                min_ans = min(min_ans, 1 + func(s,is_palindrome,m+1));
            }
        }

        return dp[i] = min_ans;
    }
};