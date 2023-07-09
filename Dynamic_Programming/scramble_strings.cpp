#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[31][31][31][31];
    bool isScramble(string& s1, string& s2) {
        int n = s1.length();
        int m = s2.length();

        memset(dp,-1,sizeof(dp));

        return solve(s1,s2,0,n-1,0,m-1);
    }
    
    bool solve(string& s1, string& s2, int i, int j, int l, int m){
        if( i == j && l == m ) return s1[i] == s2[l];
        if( i > j || l > m ) return false;

        if( dp[i][j][l][m] != -1 ) return dp[i][j][l][m];

        int ans = false;
        
        for(int k=i; k<j; k++){
            int temp = false, temp2 = false;
            temp = solve(s1,s2,i,k,l,l+k-i) && solve(s1,s2,k+1,j,l+k-i+1,m);
            temp2 = solve(s1,s2,k+1,j,l,l+j-k-1) && solve(s1,s2,i,k,l+j-k,m);
            if( temp || temp2 ){
                return dp[i][j][l][m] = true;
            }
        }
        return dp[i][j][l][m] = false;
    }

};
