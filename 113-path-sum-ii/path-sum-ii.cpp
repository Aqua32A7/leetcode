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
    void solve(vector<vector<int>>& ans,vector<int>& list,TreeNode* root, int targetSum,int curr){
        if(root==NULL){
            return;
        }
        curr+=root->val;
        list.push_back(root->val);
        if(root->left==NULL && root->right==NULL && curr==targetSum){
            ans.push_back(list);
        }
        else{
            solve(ans,list,root->left,targetSum,curr);
            solve(ans,list,root->right,targetSum,curr);
        }

        list.pop_back();


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> list;
        solve(ans,list,root,targetSum,0);
        return ans;
        
    }
};