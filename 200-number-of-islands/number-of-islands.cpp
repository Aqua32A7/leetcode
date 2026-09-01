class Solution {
public:
    void dfs(vector<vector<char>>& grid,int row,int col){
        int m = grid.size();
        int n = grid[0].size();
        

        if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == '0') {
            return;
        }

        grid[row][col]='0';

        dfs(grid,row+1,col);
        dfs(grid,row-1,col);
        dfs(grid,row,col+1);
        dfs(grid,row,col-1);


    }
    int numIslands(vector<vector<char>>& grid){
        int ans=0;
        int n=grid.size();
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(grid[row][col]=='1'){
                    dfs(grid,row,col);
                    ans++;
                }
            }
        }
        return ans;

        
    }
};