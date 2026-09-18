class Solution {
public:
    int countPaths(int n, vector<vector<int>>& flights) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        vector<long long> dist(n,1e18),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        q.push({0,0});
        int mod=int(1e9+7);
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int node=it.second;
            long long dis=it.first;


            for(auto iter:adj[node]){
                int adjnode=iter.first;
                long long wt=iter.second;
                if(dis+wt<dist[adjnode]){
                    dist[adjnode]=dis+wt;
                    q.push({dis+wt,adjnode});
                    ways[adjnode]=ways[node];
                }
                else if(dis+wt==dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }

        return ways[n-1] % mod;
    }
};