#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cost[101][101];
    int dp[101][101];
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        if( n == k ) return 0;
        memset(dp,-1,sizeof(dp));

        sort(houses.begin(),houses.end());

        memset(cost,0,sizeof(cost));

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int mid = (j+i)/2;
                for(int k=i; k<=j; k++){
                    cost[i][j] += abs(houses[k] - houses[mid]);
                }
            }
        }

        return func(cost,0,n,k);

    }

    int func(int cost[][101], int i, int n, int k){
        
        if( i == n && k == 0 ) return 0;
        if( i == n || k == 0 ) return 1e7;
        if( dp[i][k] != -1 ) return dp[i][k];

        int min_ans = 1e7;
        
        for(int m=i; m<n; m++){
            min_ans = min(min_ans,cost[i][m] + func(cost,m+1,n,k-1));
        }

        return dp[i][k] = min_ans;
    }

    
};

int main(){
    vector<int> v{1,4,8,10,20};
    cout<<Solution{}.minDistance(v, 3);
}