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
    int check(TreeNode* root,int& ans){
        if(root==NULL){
            return 0;
        }
        int lf = max(check(root->left, ans), 0);
        int rt = max(check(root->right, ans), 0);

        ans=max(ans,root->val+rt+lf);


        return max(lf,rt)+root->val;

    }
    int maxPathSum(TreeNode* root) {

        int ans=INT_MIN;
        check(root,ans);

        return ans;

        
    }
};