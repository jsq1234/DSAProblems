#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dr[101][101];
    int palindromePartition(string& s, int k) {
        memset(dr,0,sizeof(dr));
        int n = s.length();
        
        for(int i=0; i<n; i++){
            dr[i][i] = 1;
            if( i < n-1 && s[i] == s[i+1] ) dr[i][i+1] = 1;
        }

        for(int len=3; len<=n; len++){
            for(int i=0; i<= n - len; i++){
                int j = i + len - 1;
                if(s[i] == s[j] && dr[i+1][j-1]){
                    dr[i][j] = 1;
                }
            }
        }

        // dr[i][j] -> s[i..j] is palindrome or not
    }    

    int solve(string& s, int i){
        int n = s.length();
        if( i >= n ) return 0;
        
        for(int k=i; k<n; k++){
            
        }
        
    }
};
