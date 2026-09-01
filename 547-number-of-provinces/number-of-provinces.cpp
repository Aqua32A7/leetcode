class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<int>& vis,int i){
        vis[i]=1;
        int n=isConnected.size();
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1 && !vis[j]){
                dfs(isConnected,vis,j);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(isConnected,vis,i);
                c++;
            }
        }
        return c;

       
        
    }
};