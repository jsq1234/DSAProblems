/*

[4,3,1,4]
[1,3,7,1]
3;

[3,8,5,2]
[2,4,1,6]
1;

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

         if(k == 0){
            for(int i=0; i<n; i++){
                if(nums1[i] != nums2[i]) return -1;
            }
            return 0;
        }
        for(int i=0; i<n; i++){
            if((nums1[i] - nums2[i])%k != 0 ) return -1;
        }

        vector<int> vec(n,0);
        long long sum = 0;
        for(int i=0; i<n; i++){
            vec[i] = (nums2[i]-nums1[i])/k;
            sum += vec[i];
        }
        
        if(sum != 0) return -1;

        long long count = 0;
        for(int i=0; i<n; i++){
            if(vec[i]>0){
                count += vec[i];
            }
        }
        return count;
    }
};