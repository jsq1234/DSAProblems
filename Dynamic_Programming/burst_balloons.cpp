#include <bits/stdc++.h>
using namespace std;

class Solution {
public:  
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return func(nums,1,n);
    }
    /*  func(i,j,k)
        k[0] :- the un-bursted balloon before i
        k[1] :- the un-bursted balloon after j */
    int func(vector<int>& nums, int i, int j){
        if( i > j ) return 0;

        int res = INT_MIN;

        for(int m=i; m<=j; m++){
            int score = nums[m-1]*nums[m]*nums[m+1];
            res = max(res, score + func(nums,i,m-1) + func(nums,m+1,j));
        }

        return res;
    }
};

int main(){
    vector<int> nums{3,1,5,8};
    Solution sol;
    cout<<sol.maxCoins(nums)<<endl;
}
