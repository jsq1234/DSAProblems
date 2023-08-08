/*

[3,4,5,1,2];

[4,5,6,7,0,1,2];

[11,13,15,17];

*/
class Solution {
public:
    int findMin(vector<int>& nums) {
               int n = nums.size();
        int low = 0;
        int high = n - 1;

        if (nums[0] < nums[n - 1]) {
            return nums[0];
        }

        int ans = 1e9;
        while (low <= high) {
            int mid = (low + high) / 2;
            ans = min(ans, nums[mid]);
            //cout<<nums[mid]<<endl;
            if (nums[low] <= nums[mid]) {
                if(nums[mid] > nums[high]){
                   low = mid + 1;
                }else{
                    high = mid - 1;
                }
            } else {
                if(nums[mid] < nums[high]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
        }

        return ans;

    }
};
