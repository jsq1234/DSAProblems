class Solution {
public:
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> cur;
        vector<vector<int>> ans;
       solve(candidates,target,ans,cur,0);
       return ans;
    }
    void solve(vector<int>& candidates, int target,
    vector<vector<int>>& ans, vector<int>& cur, int i){
        if(target==0){
            ans.push_back(cur);
            return ;
        }
        int n = candidates.size();
        
        while( i<n && (target - candidates[i] >= 0)){
            cur.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,cur,i);
            i++;
            cur.pop_back();
        }
    }

};
