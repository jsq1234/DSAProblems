#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        sort(env.begin(),env.end(),
        [](vector<int>& p1, vector<int>& p2){
            return p1[0] < p2[0];
        });

        vector<int> dp(n,1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(env[j][1] < env[i][1] && env[j][0] < env[i][0] && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        int a1 = *max_element(dp.begin(),dp.end());
        vector<int> pp(n,1);
        sort(env.begin(),env.end(),
        [](vector<int>& p1, vector<int>& p2){
            return p1[1] < p2[1];
        });

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(env[j][0] < env[i][0] && env[j][1] < env[i][1] && pp[j] + 1 > pp[i]){
                    pp[i] = pp[j] + 1;
                }
            }
        }

        int a2 = *max_element(pp.begin(),pp.end());

        return max(a1,a2);
    }
};


int main(){
  Solution sol;
  vector<vector<int>> num1;
}
