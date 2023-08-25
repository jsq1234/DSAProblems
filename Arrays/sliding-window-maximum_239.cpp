/*

[1,3,-1,-3,5,3,6,7]
3;

[1]
1;

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> st;
        
        unordered_map<int,int> mp;
        
        for(int i=0; i<k; i++) 
        {
            st.insert(nums[i]);
            mp[nums[i]]++;
        }

        int n = nums.size();

        vector<int> ans;
        ans.push_back(*st.rbegin());

        for(int i=1; i<n-k+1; i++){
            mp[nums[i-1]]--;
            mp[nums[i+k-1]]++;
            if(mp[nums[i-1]] == 0){
                st.erase(nums[i-1]);
            }
            st.insert(nums[i+k-1]);
            ans.push_back(*st.rbegin());
        }

        return ans;

        return ans;
    }
};