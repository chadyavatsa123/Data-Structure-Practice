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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==0)continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                for(int index=0;index<4;index++){
                    int newr=r+dr[index];
                    int newc=c+dc[index];
                if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1) {
                    int nodeno=r*n+c;
                    int adjnodeno=newr*n+newc;
                    ds.unionBySize(nodeno,adjnodeno);
                }
            }
        }
    }
    int mx=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1)continue;
             int dr[]={-1,0,1,0};
             int dc[]={0,1,0,-1};
             set<int>component;
                for(int index=0;index<4;index++){
                    int newr=i+dr[index];
                    int newc=j+dc[index];
                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                        component.insert(ds.findUpar(newr*n + newc));
                    }
                }
                int maxsize=1;
                for(auto it:component){
                    maxsize+=ds.size[it];
                }
               mx=max(mx,maxsize); 
        }
    }
    for(int nodeno=0;nodeno<n*n;nodeno++){
        mx=max(mx,ds.size[ds.findUpar(nodeno)]);
    }
    return mx;
    }
};