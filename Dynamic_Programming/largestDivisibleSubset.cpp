#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> prev(n,-1);
        sort(nums.begin(),nums.end());

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j] == 0 && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
        
        int idx = max_element(dp.begin(),dp.end()) - dp.begin();
        vector<int> ans;
        //cout<<idx<<endl;
        while(idx >= 0){
            ans.push_back(nums[idx]);
            idx = prev[idx];
        }

        return ans;
    }
};
