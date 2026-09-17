class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) {
          return -1;
        }
        if (n == 1 && m == 1) {
            return 1;
        }
        queue<pair<int,pair<int,int>>> q; 

        vector<vector<int>> dist(n,vector<int>(m,1e9));

        int dr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
        int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};
        q.push({1,{0,0}});
        dist[0][0]=0;

        while(!q.empty()){
            auto node=q.front();

            q.pop();
            int d=node.first;
            int r=node.second.first;
            int c=node.second.second;
            for(int i=0;i<8;i++){
                int newr=dr[i]+r;
                int newc=dc[i]+c;
                if(newr<n && newr>=0 && newc<m && newc>=0 && grid[newr][newc]==0 && d+1<dist[newr][newc]){
                    dist[newr][newc]=d+1;
                    if(newr==n-1 && newc==m-1){
                        return d+1;
                    }
                    q.push({1+d,{newr,newc}});
                }
            }

        }
        return -1;

        
    }
};