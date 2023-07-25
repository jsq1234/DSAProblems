/*

[8,15,10,20,8]
2;

[6,1,3,2,2,4,1,2]
3;

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
       vector<int> child(k,0);
       int minUnfairness = INT_MAX;
       solve(cookies,0,child,minUnfairness);
       return minUnfairness;
    }
    void solve(vector<int>& cookies, int idx, vector<int>& child, int& minUnfairness){
        if(idx >= cookies.size() ){
            int maxCookies = *max_element(child.begin(),child.end());
            minUnfairness = min(minUnfairness,maxCookies);
            return ;
        }
        for(int j=0; j<child.size(); j++){
            child[j] += cookies[idx];
            solve(cookies,idx+1,child,minUnfairness);
            child[j] -= cookies[idx];
        }
    }
};
