#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int SubsetSum_1(vector<int>& nums, int target){
	int n = nums.size();
	vector<vector<bool>> dp(n+1,vector<bool>(target+1,0));
	// dp[i][j] = do we have elements in arr[0...i] such that they add up to j?
	

	dp[0][0] = true;

	for(int j=1; j<=target; j++){
		for(int i=1; i<=n; i++){
			if(  j <= nums[i-1] ){
				dp[i][j] = dp[i][j] or dp[i-1][j-nums[i-1]];
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][target];
}
int main(){
	vector<int> arr{3,2,1,2,3,4,6,11,2};
	cout<<SubsetSum_1(arr,9);
}
