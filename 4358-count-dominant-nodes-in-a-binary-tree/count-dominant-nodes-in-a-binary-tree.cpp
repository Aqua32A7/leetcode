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
    int ans=0;
    void dfs(TreeNode* root,int& maxi){
        if(!root){
            maxi=INT_MIN;
            return ;
        }
        int lefti = INT_MIN, righti = INT_MIN;
        dfs(root->left,lefti);
        dfs(root->right,righti);
        if(root->val >=lefti && root->val>=righti){
            ans++;
        }
        maxi = max({root->val, lefti, righti});
    }
    int countDominantNodes(TreeNode* root) {
        ans=0;
        int maxi=INT_MIN;
        dfs(root,maxi);
        return ans;
        
    }
};