/*

[3,2,3]
3;

[1,2,4,7,8]
2;

[9899456,8291115,9477657,9288480,5146275,7697968,8573153,3582365,3758448,9881935,2420271,4542202]
9;

[46,13,54,51,38,49,54,67,26,78,33]
10;

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int K;
    int minimumTimeRequired(vector<int>& jobs, int k) {
        n = jobs.size();
        K = k;
        sort(jobs.begin(),jobs.end(),greater<int>());
        vector<int> workers(k,0);        
        int ans = INT_MAX;
        solve(0,jobs,workers,ans);
        return ans; //help(0,jobs,workers,-1,INT_MAX,dp);
    }
    // Gives TLE
    void solve(int idx, vector<int>& jobs, vector<int>& workers, int& ans){
        if(idx >= n){
            int maxElem = *max_element(workers.begin(),workers.end());
            ans = min(ans,maxElem);
            return ;
        }

        if(*max_element(workers.begin(),workers.end()) >= ans){
            return ;
        }

        for(int j=0; j<K; j++){
            if(j > 0 && workers[j] >= workers[j-1]) continue;
            workers[j] += jobs[idx];
            solve(idx+1,jobs,workers,ans);
            workers[j] -= jobs[idx];
        }
    }

    // Also gives TLE
    int help(int idx, vector<int>& jobs, vector<int>& workers, int maxVal, int ans, map<pair<int,vector<int>>,int>& dp){
        if(idx >= n){
            return maxVal;
        }

        if(dp.find({idx,workers}) != dp.end()) return dp[{idx,workers}];

        if(maxVal >= ans) return dp[{idx,workers}] = ans; 

        for(int j=0; j<K; j++){
            workers[j] += jobs[idx];
            ans = min(ans, help(idx+1,jobs,workers,max(maxVal,workers[j]),ans, dp));
            workers[j] -= jobs[idx];
        }
        return dp[{idx,workers}] = ans;
    }

};