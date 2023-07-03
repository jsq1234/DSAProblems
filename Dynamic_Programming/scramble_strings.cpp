#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isScramble(string& s1, string& s2) {
        int n = s1.length();
    }

    /* solve(s1, s2, i, j) */
    bool solve(string& s1, string& s2, int i, int j){
        if( i > j ) return false;
        if( s1.substr(i,j-i+1) == s2.substr(i,j-i+1) ){
            return true;
        }
    }
};