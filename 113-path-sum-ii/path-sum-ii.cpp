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
    void solve(vector<vector<int>>& ans,vector<int>& list,TreeNode* root, int targetSum){
        if(root==NULL){
            return;
        }
        list.push_back(root->val);
        if(root->left==NULL && root->right==NULL && root->val==targetSum){
            ans.push_back(list);
        }
        else{
            solve(ans,list,root->left,targetSum-root->val);
            solve(ans,list,root->right,targetSum-root->val);
        }

        list.pop_back();


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> list;
        solve(ans,list,root,targetSum);
        return ans;
        
    }
};