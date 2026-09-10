class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto pre:prerequisites){
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int> ans(numCourses);

        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            ans[count++]=node;

            for(int next: adj[node]){
                indegree[next]--;
                if(indegree[next]==0) q.push(next);
            }

        }

        if(count!=numCourses) return {};
        return ans;
        
    }
};