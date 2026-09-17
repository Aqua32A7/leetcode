class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        // if (grid[0][0] == 1 || grid[n-1][m-1] == 1) {
        //   return -1;
        // }
        // if (n == 1 && m == 1) {
        //     return 1;
        // }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

        vector<vector<int>> dist(n,vector<int>(m,1e9));

        int dr[] = {-1, 1, 0,  0};
        int dc[] = {0,  0,  1, -1};
        q.push({0,{0,0}});
        dist[0][0]=0;

        while(!q.empty()){
            auto node=q.top();

            q.pop();
            int d=node.first;
            int r=node.second.first;
            int c=node.second.second;
            if(r==n-1 && c==m-1){
                return d;
            }
            for(int i=0;i<4;i++){
                int newr=dr[i]+r;
                int newc=dc[i]+c;
                if(newr<n && newr>=0 && newc<m && newc>=0){
                    int di=max(d,abs(grid[r][c]-grid[newr][newc]));
                    if(di<dist[newr][newc]){
                        dist[newr][newc]=di;
                        q.push({di,{newr,newc}});
                    }
                }
            }

        }
        return -1;
    }
};