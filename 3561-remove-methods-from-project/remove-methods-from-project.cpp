class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<int>&suspicious){
     suspicious[node]=1;
     for(auto it:adj[node]){
        if(!suspicious[it])
        dfs(it,adj,suspicious);
     }

    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>suspicious(n,0);
        vector<int>adj[n];
        for(int i=0;i<invocations.size();i++){
            int u=invocations[i][0];
            int v=invocations[i][1];
            adj[u].push_back(v);
        }
        
         dfs(k,adj,suspicious);
        
       
        bool remove=true;
        for(int i=0;i<invocations.size();i++){
            int u=invocations[i][0];
            int v=invocations[i][1];
            if(!suspicious[u] && suspicious[v]){
                remove =false;
                break;
            }
        }
        if(remove==false){
            vector<int>ans;
            for(int i=0;i<n;i++){
              ans.push_back(i);
            }
            return ans;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!suspicious[i])
           ans.push_back(i);
        }
        return ans;
    }
};