#include <iostream>
#include <vector>
using namespace std; 

/*
 * Number of ways to obtain target using elements of nums either by 
 * addition or substraction
 * 
*/
class Solution{
	public:
		int subsetSum2(vector<int>& nums, int target){
			int n = nums.size();
			return solve(n-1,nums,target);
		}
		int solve(int i, vector<int>& nums, int target){
			if(!target) return 1;
			if(i<0) return 0;
			return solve(i-1,nums,target)+solve(i-1,nums,target-nums[i])+solve(i-1,nums,target+nums[i]);
		}
};
int main(){
	Solution obj;
	vector<int> nums{3,-1,2,4};
	cout<<obj.subsetSum2(nums,5)<<endl;
}
