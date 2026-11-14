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
    void convert(TreeNode* root,int& ans){
        if(root==NULL ){
            return;
        }
        convert(root->right,ans);
        ans+=root->val;
        root->val=ans;
        convert(root->left,ans);

    }
    TreeNode* convertBST(TreeNode* root){
        int ans=0;
        convert(root,ans);
        return root;
    }
};