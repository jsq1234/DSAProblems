/*

[1,2,1];

[1,2,3,4,3];

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i=0; i<n; i++){
            int r = (i+1)%n;
            while(r != i && nums[r] <= nums[i]){
                r = (r+1)%n;
            }
            if(r==i) ans[i] = -1;
            else ans[i] = nums[r];
        }
        return ans;
    }
};
