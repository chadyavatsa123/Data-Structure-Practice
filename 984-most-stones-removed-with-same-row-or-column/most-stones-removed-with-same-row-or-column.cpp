class DisjointSet{
    public:
    vector<int>parent,size;
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
    int removeStones(vector<vector<int>>& stones) {
        int n=0;
        for(auto it:stones)
        n++;
        int totalrow=0;
        int totalcol=0;
        for(auto it:stones){
           totalrow=max(totalrow,it[0]);
           totalcol=max(totalcol,it[1]);
        }
        DisjointSet ds(totalrow+totalcol+1);
        unordered_map<int,int>mp;
        for(auto it:stones){
            int row=it[0];
            int col=totalrow+1+it[1];
            ds.unionBySize(row,col);
            mp[row]=1;
            mp[col]=1;
        }
        int connecteduniquecomp=0;
        for(auto it:mp){
            if(it.first==ds.findUpar(it.first))
            connecteduniquecomp++;
        }
        return n-connecteduniquecomp;
    }
};