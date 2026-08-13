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
    TreeNode* solve(TreeNode* root){
        if(root->left==NULL){
            return root->right;
        }
        if(root->right==NULL){
            return root->left;
        }
        TreeNode* rightChilde=root->right;
        TreeNode* lastRight=check(root->left);
        lastRight->right=rightChilde;
        return root->left;

    }

    TreeNode* check(TreeNode* root){
        if(root->right==NULL){
            return root;
        }

        return check(root->right);
    }


    TreeNode* deleteNode(TreeNode* root, int key){
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            return solve(root);
        }
        TreeNode* dummy=root;
        while(root!=NULL){
            if(root->val>key){
                if(root->left!=NULL && root->left->val==key){
                    root->left=solve(root->left);
                    break;
                }

                else{
                    root=root->left;
                }
            }

            else{
                if(root->right!=NULL && root->right->val==key){
                    root->right=solve(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        return dummy;
    }
};