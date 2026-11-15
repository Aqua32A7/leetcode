/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void buildGraph(TreeNode* node, unordered_map<TreeNode*,vector<TreeNode*>>& graph){
        if (node == nullptr) {
            return;
        }
        if (node->left != NULL) {
            graph[node].push_back(node->left);
            graph[node->left].push_back(node);

            buildGraph(node->left, graph);
        }

        if (node->right != NULL) {
            graph[node].push_back(node->right);
            graph[node->right].push_back(node);

            buildGraph(node->right, graph);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*,vector<TreeNode*>> graph;
        buildGraph(root,graph);
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        int curr=0;
        while(!q.empty()){
            if(curr==k){
                break;
            }
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                for(auto nodes:graph[node]){
                    if(visited.find(nodes) == visited.end()){
                        visited.insert(nodes);
                        q.push(nodes);
                    }
                }

            }
            curr++;
        }

        while (!q.empty()) {
            ans.push_back(
                q.front()->val
            );
            q.pop();
        }
        return ans;

        
    }
};