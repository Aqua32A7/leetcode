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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        int c=0;
        while(!q.empty()){
            
            int sz=q.size();
            vector<int> nums;

            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                nums.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(c%2==0){
                ans.push_back(nums);
            }
            else{
                reverse(nums.begin(),nums.end());
                ans.push_back(nums);
            }
            c++;
            
        }
        return ans;
    }
};