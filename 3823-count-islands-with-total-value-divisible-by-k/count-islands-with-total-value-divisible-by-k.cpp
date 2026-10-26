class Solution {
public:
    long long dfs(vector<vector<int>>& grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0){
            return 0;
        }
        
        long long current_sum = grid[i][j];
        grid[i][j] = 0; 
        
        current_sum += dfs(grid, i + 1, j);
        current_sum += dfs(grid, i - 1, j);
        current_sum += dfs(grid, i, j + 1);
        current_sum += dfs(grid, i, j - 1);
        
        return current_sum;
        
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    long long sum=dfs(grid,i,j);
                    if(sum%k==0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};