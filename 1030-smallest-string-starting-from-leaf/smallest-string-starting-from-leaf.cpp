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
    void solve(TreeNode* root,string& ans,string s){
        if(root==NULL) return;
        s+=char('a' + root->val);

        if(root->left==NULL && root->right==NULL){
            reverse(s.begin(),s.end());
            if(ans.empty() ||s<ans){
                ans=s;
            }
            reverse(s.begin(),s.end());

        }
        solve(root->left,ans,s);
        solve(root->right,ans,s);

    }
    string smallestFromLeaf(TreeNode* root) {
        string ans="";
        solve(root,ans,"");
        return ans;
        
    }
};