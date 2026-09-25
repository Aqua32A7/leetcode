class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms){
        queue<int> q;
        q.push(0);
        vector<int> check(rooms.size(),0);
        check[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<rooms[node].size();i++){
                if(check[rooms[node][i]]==0){
                    check[rooms[node][i]]=1;
                    q.push(rooms[node][i]);
                }
            }
        }
        for(int i=0;i<check.size();i++){
            if(check[i]==0){
                return false;
            }
        }
        return true;
        
    }
};