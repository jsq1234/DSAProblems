/*

"aabcc"
"dbbca"
"aadbbcbcac";

"aabcc"
"dbbca"
"aadbbbaccc";

""
""
"";

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string& s1, string& s2, string& s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();

        if(n3 != n1 + n2) return false;

        return solve(s1,s2,s3,n1-1,n2-1,n3-1);
    }
    bool solve(string& s1, string& s2, string& s3, int i, int j, int k){
        
        if( k == 0 ){
            return i == 0 && j == 0;
        }

        if( i == 0 && j == 0 ) return k == 0;
        
        if( j == 0 ){
            return s1.substr(0,i+1) == s3.substr(0,k+1);
        }
        
        if( i == 0 ){
            return s1.substr(0,j+1) == s3.substr(0,k+1);
        }
        
        if(s1[i] == s3[k] && s2[j] == s3[k]){
            return solve(s1,s2,s3,i-1,j,k-1) || solve(s1,s2,s3,i,j-1,k-1);
        }
        else if(s1[i] == s3[k]){
            return solve(s1,s2,s3,i-1,j,k-1);
        }else if(s2[j] == s3[k]){
            return solve(s1,s2,s3,i,j-1,k-1);
        }

        return false;
    }
};