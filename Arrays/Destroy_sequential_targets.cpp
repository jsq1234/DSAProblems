#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        unordered_map<int,int> rem;
        vector<int> arr(n,0);
        for(int i=0; i<n; i++){
            arr[i] = nums[i]%space;
            rem[arr[i]]++;
        }

        int max_ans = 0;
        int val = INT_MAX;
        for(int i=0; i<n; i++){
            if( rem[arr[i]] >= max_ans ){
                if( rem[arr[i]] == max_ans ){
                    val = min(val,nums[i]);
                }else{
                    val = nums[i];
                }
                max_ans = rem[arr[i]];
            }
        }

        return val;

    }
};
