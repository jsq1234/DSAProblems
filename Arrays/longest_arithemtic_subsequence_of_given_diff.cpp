#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums, int diff) {
        unordered_map<int,int> dp;
        int n = nums.size();
        int max_len = 1;

        for(int i=0; i<n; i++){
            int val1 = nums[i] - diff;
            
            int a = dp.count(val1) ? dp[val1] + 1 : 1;

            dp[nums[i]] = a;

            max_len = max(max_len,a);
        }

        return max_len;
    }
};
