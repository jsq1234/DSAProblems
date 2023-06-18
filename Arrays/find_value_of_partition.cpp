#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int diff = INT_MAX;
        
        for(int i=n-1; i>0; i--){
            diff = min(diff, abs(nums[i] - nums[i-1]));
        }
        
        return diff;

    }
};
