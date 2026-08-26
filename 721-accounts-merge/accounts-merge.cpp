class DisjointSet{
    vector<int>parent,size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUpar(int node){
        if(node==parent[node])
        return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v)return;
        else if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DisjointSet ds(accounts.size());
        unordered_map<string,int>mp;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }
                else{
                    ds.unionBySize(i,mp[mail]);
                }
            }
        }
        vector<string>adj[accounts.size()];
        for(auto it:mp){
           string mail=it.first;
           int node=ds.findUpar(it.second);
           adj[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<accounts.size();i++){
            if(adj[i].size()==0)continue;
            sort(adj[i].begin(),adj[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:adj[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);

        }
        return ans;
    }
};