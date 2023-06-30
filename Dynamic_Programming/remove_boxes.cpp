#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[101][101][101];
    int removeBoxes(vector<int>& boxes) {
        memset(dp,-1,sizeof(dp));
        return solve(boxes,0,boxes.size()-1,0);
    }
    int solve(vector<int>& boxes, int i, int j, int k){

        if( i > j )  return 0;

        if( dp[i][j][k] != -1 ) return dp[i][j][k];


        int ans = (k+1)*(k+1) + solve(boxes,i+1,j,0);

        for(int m=i+1; m<=j; m++){
            if( boxes[m] == boxes[i] ){
                ans = max(ans,
                solve(boxes,i+1,m-1,0) + solve(boxes,m,j,k+1));
            }
        }

        return dp[i][j][k] = ans;
    }
};
