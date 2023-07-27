/*

"tbgtgb";

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strangePrinter(string& s) { 
        return solve(s,0,s.length());
    }

    int solve(string& s, int i, int j){
        if( i >= j ) return 0;
        char ch = s[i];
        int count = 1;
        for(int k=i; k<j;){
            if(s[k] != ch){
               int r = k;
               while(r<j && s[r] != ch) r++;
               count += solve(s,k,r);
               k = r;
               continue;
            }
            k++;
        }
        return count;
    }
};


