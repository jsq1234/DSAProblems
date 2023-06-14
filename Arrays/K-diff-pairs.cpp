#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> st;
        int n = nums.size();
        if(n == 1) return 0;
        
        int count = 0;
        if( k == 0 ){
            unordered_map<int,int> mp;
            for(int i=0; i<n; i++){
                mp[nums[i]]++;
            }
            for(auto p : mp){
                if(p.second >= 2){
                    count++;
                }
            }
            return count;
        } 
        st.insert(nums[0]);
        for(int i=1; i<n; i++){
            if( k != 0 && st.find(nums[i]) != st.end() ) continue;
            if( st.find(nums[i]-k) != st.end() ){
                
                count += 1;
            }
            if( st.find(nums[i] + k) != st.end() ){
                
            }
            st.insert(nums[i]);
        }

        return count;
    }
};
