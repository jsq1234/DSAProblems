/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        unordered_map<TreeNode*,int> mp;
        getMax(root,mp);
        queue<TreeNode*> q;
        q.push(root);
        int maxSum = -1e9;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto node = q.front();
                q.pop();
                int left = node->left ? mp[node->left] : -1e9;
                int right = node->right ? mp[node->right] : -1e9;
                maxSum = max({maxSum,left+node->val,right+node->val,left+right+node->val,node->val});
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return maxSum == -1e9 ? 0 : maxSum;
    }


    int getMax(TreeNode* node, unordered_map<TreeNode*,int>& mp){
        if(!node) return 0;
        int left = getMax(node->left,mp);
        int right = getMax(node->right,mp);
        return mp[node] = max({left+node->val,right+node->val,node->val});
    }

};
