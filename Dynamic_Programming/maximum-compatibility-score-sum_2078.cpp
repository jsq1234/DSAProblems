/*

[[1,1,0],[1,0,1],[0,0,1]]
[[1,0,0],[0,0,1],[1,1,0]];

[[0,0],[0,0],[0,0]]
[[1,1],[1,1],[1,1]];

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> st;
    vector<vector<int>> me;
    int dp[10][1<<8];
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        int n = students[0].size();
        st = students;
        me = mentors;
        int maxScore = 0;
        vector<int> visited(m,0);
        //solve(0,n,m,visited,0,maxScore);
        int mask = 0;
        memset(dp,-1,sizeof(dp));
        return bitmask(0,mask,n,m);
        return maxScore;
    }

    // Using backtracking 
    void solve(int idx, int n, int m, vector<int>& visited, int score, int& maxScore){
        
        if(idx >= m ){
            maxScore = max(maxScore,score);
            return ;
        }
        
        vector<int> t = st[idx];
        for(int i=0; i<m; i++){
            if(!visited[i]){
                int compat_score = 0;
                vector<int> u = me[i];
                for(int j=0; j<n; j++) if(u[j] == t[j]) compat_score++;
                visited[i] = 1;
                solve(idx+1,n,m,visited,score+compat_score,maxScore);
                visited[i] = 0;
            }
        }
    }

    // Using dp + bitmasking


    int bitmask(int idx, int mask, int n, int m){
        if(idx >= m){
            return 0;
        }
        if(dp[idx][mask] != -1 ) return dp[idx][mask];

        vector<int> t = st[idx];
        int maxScore = 0;
        for(int i=0; i<m; i++){
            if((mask&(1<<i)) == 0){
                int score = 0;
                vector<int> u = me[i];
                for(int j=0; j<n; j++) if(t[j] == u[j]) score++;
                maxScore = max(maxScore, score + bitmask(idx+1,mask^(1<<i),n,m));
            }
        }

        return dp[idx][mask] = maxScore;
    }
};

/* 

*/