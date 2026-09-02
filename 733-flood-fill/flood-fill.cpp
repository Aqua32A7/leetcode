class Solution {
public:
    void dfs(vector<vector<int>>& image,int row,int col,int color,int originalColor){

        int m = image.size();
        int n = image[0].size();

        if(row < 0 || row >= m || col < 0 || col >= n || image[row][col] != originalColor){
            return;
        }

        image[row][col]=color;

        dfs(image,row+1,col,color,originalColor);
        dfs(image,row-1,col,color,originalColor);
        dfs(image,row,col+1,color,originalColor);
        dfs(image,row,col-1,color,originalColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor=image[sr][sc];
        if(originalColor!=color){
            dfs(image,sr,sc,color,originalColor);

        }

        return image;
    }
};