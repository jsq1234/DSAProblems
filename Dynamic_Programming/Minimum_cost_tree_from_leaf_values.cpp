#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int dp[45][45];
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<int> left_max(n);
        vector<int> right_max(n);

        memset(dp,-1,sizeof(dp));

        int hmm = INT_MIN;
        for(int i=0; i<n; i++){
            hmm = max(hmm,arr[i]);
            left_max[i] = hmm;
        }

        hmm = INT_MIN;
        for(int i=n-1; i>=0; i--){
            hmm = max(hmm,arr[i]);
            right_max[i] = hmm;
        }

        return solve(arr,left_max,right_max,0,n-1);
    }

    int solve(vector<int>& arr,vector<int>& lmax, vector<int>& rmax, int i, int j){
        if( i > j ) return 0;
        // two elements
        if( i == j ) return 0;

        if( i + 1 == j ) return arr[i]*arr[i+1]; 

        if( dp[i][j] != -1 ) return dp[i][j];

        int ans = 1e6;
        for(int m=i+1; m<j; m++){
            int a1 = solve(arr,lmax,rmax,i,m) + solve(arr,lmax,rmax,m+1,j) + lmax[m]*rmax[m+1];
            int a2 = solve(arr,lmax,rmax,i,m-1) + solve(arr,lmax,rmax,m,j) + lmax[m-1]*rmax[m];
            ans = min({ans,a1,a2});
        }

        return dp[i][j] = ans;
    }
};

 
