class DisjoinSet{
    vector<int>parent,size;
    public:
    DisjoinSet(int n){
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
    void unionBySize(int u,int v,int &extra){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v){
        extra++;
        return;
        }
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjoinSet ds(n);
       // if(connections.size()<n-1)return -1;
        int extra=0;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            ds.unionBySize(u,v,extra);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.findUpar(i)==i)
              cnt++;
        }
        if(extra>=cnt-1)
        return cnt-1;
        else return -1;
    }
};