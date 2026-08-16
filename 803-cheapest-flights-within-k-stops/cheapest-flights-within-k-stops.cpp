class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int>dist(n,INT_MAX);
        queue<pair<int,pair<int,int>>>q;
         q.push({0,{src,0}});
         dist[src]=0;
         while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stops>k)continue;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edgeweight=it.second;
                if(cost+edgeweight < dist[adjnode] && stops<=k){
                    dist[adjnode]=cost+edgeweight;
                    q.push({stops+1,{adjnode,dist[adjnode]}});
                }
            }
         }
         if(dist[dst]==INT_MAX)return -1;
         return dist[dst];
    }
};