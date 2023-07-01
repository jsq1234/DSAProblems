#include <bits/stdc++.h>
#include <numeric>
using namespace std;


class Solution
{
  public:
    int dp[51][51][51];
    int mergeStones(vector<int> &stones, int k)
    {
        memset(dp,-1,sizeof(dp));

        int n = stones.size();
        vector<int> prefix(n+1,0);

        for(int i=1; i<=n; i++){
            prefix[i] = prefix[i-1] + stones[i-1];
        }

        if( (n-1) % (k-1) != 0 ) return -1;

        return func(prefix,1,n,1,k);
    }
    /*  
        func(i,j,p,k) -> mininum cost to merge stones[i..j] into p piles 
        func(0,n-1,1,k) -> minumum cost to merge stones[0..n-1] into 1 piles (what we want)

    */  
    int func(vector<int>& prefix_sum, int i, int j, int p, int k){
        if( i == j && p == 1 ) return 0;

        if( i == j ) return 1e5;

        if( dp[i][j][p] != -1 ) return dp[i][j][p];
        
        if( p == 1 ){
            return dp[i][j][p] = func(prefix_sum,i,j,k,k) + prefix_sum[j] - prefix_sum[i-1];
        }

        int res = 1e5;
        for(int m=i; m<j; m++){
            int temp = func(prefix_sum,i,m,1,k) + func(prefix_sum,m+1,j,p-1,k);
            res = min(res,temp);
        }
        return dp[i][j][p] = res;
    }
    

};

int main()
{
    vector<int> vec{3,2,4,1};
    cout << Solution{}.mergeStones(vec, 2) << endl;
}