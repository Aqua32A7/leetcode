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
    long long kthLargestLevelSum(TreeNode* root, int k){
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> ans;
        while(!q.empty()){
            int sz=q.size();
            long long sum=0;
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                sum+=node->val;
                if(node->left ) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(sum);

        }
        sort(ans.rbegin(),ans.rend());
        if(ans.size()<k) return -1;
        return ans[k-1];
        
    }
};