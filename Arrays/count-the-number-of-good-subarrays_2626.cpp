/*

[1,1,1,1,1]
10;

[3,1,4,3,2,2,4]
2;

*/
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int sz = (1 + sqrt(1 + 8*k))/2;

        unordered_map<int,int> mp;
        
        for(int i=0; i<sz; i++){
            mp[nums[i]]++;
        }

        for(int i=0; i<=n-sz; i++){
            
        }   
    }
};

int main(){
    vector<int> nums{1,2,3,4,5,6,7,8,9,10};
    cout<<Solution().countGood(nums, 3)<<endl;
}