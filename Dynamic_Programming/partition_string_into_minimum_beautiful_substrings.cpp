#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    unsigned long long dp[16];
    int pp[16];
    int check(unsigned long long val){
        for(int i=0; i<15; i++){
            if(dp[i] == val) return true;
        }
        return false;
    }
    int minimumBeautifulSubstrings(string& s) {
        int n = s.length();
        
        memset(pp,-1,sizeof(pp));
        
        for(int i=0; i<15; i++) dp[i] = 1;
        
        for(int i=1; i<15; i++){
            dp[i] = dp[i-1]*5;
        }

        int ans = solve(s,0);
        
        return ans >= 1e5 ? -1 : ans;
    }

    int solve(string& s, int i){
        if( i >= s.length() ) return 0;
        if( s[i] == '0' ) return 1e5;
        
        if( pp[i] != -1 ) return pp[i];
        
        unsigned long long val = 0;
        
        int n = s.length();

        int ans = INT_MAX;
        
        for(int j=i; j<n; j++){
           val = (val<<1) | (s[j] == '1'); 
           if(check(val)){
               int r = solve(s,j+1);
               if( r >= 1e5 ){
                   continue;
               }
               ans = min(ans, 1 + r);
           }
        }

        return pp[i] = ans;
    }
};

