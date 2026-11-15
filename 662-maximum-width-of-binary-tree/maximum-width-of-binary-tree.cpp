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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        unsigned long long ans=0;
        while(!q.empty()){
            int sz=q.size();
            unsigned long long mini=q.front().second;
            unsigned long long first,last;
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                auto curr=node.first;
                unsigned long long id=node.second-mini;
                if(i==0) first=id;
                if(i==sz-1) last=id;
                if(curr->left){
                    q.push({curr->left,2*id});
                }
                if(curr->right){
                    q.push({curr->right,2*id+1});
                }
                ans=max(ans,last-first+1);
            }
        }

        return static_cast<int>(ans);
        
    }
};