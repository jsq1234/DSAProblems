#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int dp[45][45];
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,n-1);
    }

    int solve(vector<int>& arr, int i, int j){
        if( i == j ) return 0;

        if( dp[i][j] != -1 ) return dp[i][j];

        int ans = 1e6;

        for(int m=i; m<j; m++){
            int left = solve(arr,i,m);
            int right = solve(arr,m+1,j);
            int mul = *max_element(arr.begin()+i,arr.begin()+m+1)*(*max_element(arr.begin()+m+1,arr.begin()+j+1));
            int temp = left + right + mul;
            ans = min(ans,temp);
        }

        return dp[i][j] = ans;
    }
};

 
