/*

[1,3,2,3,1,3]
3;

[1,1,2,2,1,1]
2;

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,vector<vector<int>>> mp;
        for(int i=0; i<n; i++){
            if(mp.find(nums[i]) != mp.end()){
                auto& vec = mp[nums[i]].back();
                if(vec[1] + 1 == i){
                    vec[1] = i;
                }else{
                    mp[nums[i]].push_back({i,i});
                }
            }else{
                mp[nums[i]].push_back({i,i});
            }
        }
        
        int maxAns = 0;
        for(auto& key : mp){
            auto& vec = key.second;
            if(vec.size()==1){
                maxAns = max(maxAns,vec[0][1] - vec[0][0] + 1);
            }else{
                int elemCount = 0;
                int sz = vec[0][1] - vec[0][0] + 1;
                for(int i=1; i<vec.size(); i++){
                    elemCount += (vec[i-1][1] - vec[i][0] - 1);
                    if(elemCount > k){
                        maxAns = max(maxAns, sz);
                        break;
                    }
                    sz += (vec[i][1] - vec[i][0] + 1);
                }
                if(elemCount <= k){
                    maxAns = max(maxAns, sz);
                }
            }
        }
        
        return maxAns;
    }
};