class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && (i==0 || j==0 || i==n-1 || j==m-1)){
                    q.push({i,j});
                    board[i][j]='s';
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
                if(col>=0 && row>=0 && col<m && row<n && board[row][col]=='O'){
                    q.push({row,col});
                    board[row][col]='s';

                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='s'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }





        

        
    }
};