#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int drome[101][101];
    int palindromePartition(string& s, int k) {
        memset(drome,0,sizeof(drome));
        int n = s.length();
        
        for(int i=0; i<n; i++){
            drome[i][i] = 1;
            if( i < n-1 && s[i] == s[i+1] ) drome[i][i+1] = 1;
        }

        for(int len=3; len<=n-len; len++){
            
        }

    }    
};
