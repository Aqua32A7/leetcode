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
    vector<int> nums1;
    vector<int> nums2;
    void ins(TreeNode* root){
        if(root==NULL) {nums1.push_back(-1001);return;}
        nums1.push_back(root->val);
        ins(root->left);
        ins(root->right);
    }

    void ins2(TreeNode* root){
        if(root==NULL) {nums2.push_back(-1001);return;}
        nums2.push_back(root->val);
        ins2(root->left);
        ins2(root->right);
    }

    bool check(TreeNode* root, TreeNode* subRoot){
        if(root==NULL ) return false;
        if(root->val==subRoot->val){
            nums1.clear();
            nums2.clear();
            ins(root);
            ins2(subRoot);
            if(nums1 == nums2)
                return true;
            
        }
        return check(root->left,subRoot)||
        check(root->right,subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL)
            return true;

        if(root == NULL)
            return false;

        return check(root, subRoot);
        
    }
};