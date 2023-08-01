
class Solution {
public:
    set<vector<int>> st;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(candidates.begin(),candidates.end());
        solve(candidates,cur,ans,target,0);
        vector<vector<int>> res(st.begin(),st.end());
        return ans;
    }
    void solve(vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans, int target, int i){
        if(target==0){
            ans.push_back(cur);
            return ;
        }
        for(int j=i; j<nums.size();j++){
            if( j>i && nums[j] == nums[j-1] ) continue;
            if(target - nums[j] >= 0){
                cur.push_back(nums[j]);
                solve(nums,cur,ans,target-nums[j],j+1);
                cur.pop_back();
            }else{
                break;
            }
        }
    }
};

