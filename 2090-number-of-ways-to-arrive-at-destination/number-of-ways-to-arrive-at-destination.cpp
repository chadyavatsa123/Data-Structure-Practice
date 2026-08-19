class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        int mod=1e9+7;
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>>pq;
        vector<long>dist(n,LLONG_MAX);
        vector<int>ways(n,0);
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long dis=it.first;
            int node=it.second;
            for(auto it:adj[node]){
                int weight=it.second;
                int adjnode=it.first;
                if(dis+weight == dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
               else if(dis+weight < dist[adjnode]){
                    dist[adjnode]=dis+weight;
                    ways[adjnode]=ways[node];
                    pq.push({dist[adjnode],adjnode});
                }
            
            }
        }
        return ways[n-1];
    }
};