class Solution {
public:
    void dfs(vector<vector<int>>& grid,int row,int col){
        int m = grid.size();
        int n = grid[0].size();
        

        if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 1) {
            return;
        }

        grid[row][col]=1;

        dfs(grid,row+1,col);
        dfs(grid,row-1,col);
        dfs(grid,row,col+1);
        dfs(grid,row,col-1);


    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid[0].size();
        int m = grid.size();
        for(int row=0;row<m;++row){
            for(int col=0;col<n;++col){
                if((row == 0 || row == m - 1 || col == 0 || col == n - 1) && grid[row][col]==0){
                    dfs(grid,row,col);
                }
            }
        }


        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ans++;
                    dfs(grid, i, j); 
                }
            }
        }





        return ans;


    }
};