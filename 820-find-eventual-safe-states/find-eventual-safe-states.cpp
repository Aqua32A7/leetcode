class Solution {
public:
    bool dfs(int node ,vector<vector<int>>& graph,vector<int>& state){
       if( state[node]==1) return false;
       if(state[node]==2) return true;

       state[node]=1; 

        for(auto it:graph[node]){
            if(dfs(it,graph,state)==false) return false;
        }

        state[node]=2;

        return true;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> state(graph.size(),0);
        vector<int> ans;

        for(int i=0;i<graph.size();i++){
            if(dfs(i,graph,state)){
                ans.push_back(i);
            }
        }

        return ans;







        
    }
};