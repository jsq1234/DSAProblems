#include <cstring>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int mod = 1e9+7;
int dp[1006][1006];

long long solve(int N, int mx){
    if(N == 0) return 1;
    if( N < 0 ) return 0;
    if(dp[N][mx] != -1) return dp[N][mx];
    long long ans = 0;
    for(int i=1; i<=mx+1; i++){
        ans += solve(N-1,max(i,mx))%mod;
    }
    return dp[N][mx] = ans%mod;
}
int main(){
    int T=0;
    cin>>T;
    memset(dp,-1,sizeof(dp));
    while(T--){
        int N = 0;
        cin>>N;
        cout<<solve(N-1,1)<<"\n";
    }
}