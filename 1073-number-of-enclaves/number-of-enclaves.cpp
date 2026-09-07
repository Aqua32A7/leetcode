class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && (i==0 || j==0 || i==n-1 || j==m-1)){
                    q.push({i,j});
                    grid[i][j]=9;
                }
            }
        }
        int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};
        while(!q.empty()){

            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int row=r+drow[i];
                int col=c+dcol[i];
                if(col>=0 && row>=0 && col<m && row<n && grid[row][col]==1){
                    q.push({row,col});
                    grid[row][col]=9;

                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    // grid[i][j]='O';
                    ans++;
                }
            }
        }
        return ans;
        
    }
};