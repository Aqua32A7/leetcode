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
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,root->val});
        int c=0;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            TreeNode* node=temp.first;
            int maxi=temp.second;

            if(node->val>=maxi){
                c++;
            }

            int newMax=max(node->val,maxi);
            if(node->left){
                q.push({node->left,newMax});

            }

            if(node->right){
                q.push({node->right,newMax});
            }

        }
        return c;
        
    }
};