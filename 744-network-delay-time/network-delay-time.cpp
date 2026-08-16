class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,int>>q;
        vector<int>t(n+1,INT_MAX);
        q.push({0,k});

        t[k]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int time=it.first;
            int node=it.second;
            for(auto it:adj[node]){
               int dist=it.second;
               int adjnode=it.first;
               if(time+dist<t[adjnode]){
                t[adjnode]=time+dist;
                q.push({t[adjnode],adjnode});
               }
            }
        }
        int mintime=INT_MIN;
        for(int i=1;i<=n;i++){
           
          mintime=max(mintime,t[i]);
        }
        if(mintime==INT_MAX)return -1;
        return  mintime;
        
    }
};