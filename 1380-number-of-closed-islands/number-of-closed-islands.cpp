class Solution {
public:
 class DisjointSet{
   vector<int>size,parent;
public:
  DisjointSet(int n){
size.resize(n+1,1);
parent.resize(n+1);
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
    if(size[ulp_u]<size[ulp_v]){
        parent[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
    }
    else{
        parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
}

 };
 bool notvalid(int row,int col,int n,int m){
    if(row==0 || row==n-1 || col==0 ||  col==m-1)return true;
    return false;
 }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        DisjointSet ds(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)continue;
                int drow[]={-1,0,1,0};
                int dcol[]={0,1,0,-1};
                for(int ind=0;ind<4;ind++){
                    int nrow=i+drow[ind];
                    int ncol=j+dcol[ind];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0){
                        int node=i*m+j;
                        int adjnode=nrow*m+ncol;
                        ds.unionBySize(node,adjnode);
                    }
                }
            }
        }
        vector<int>visited(n*m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)continue;
                int node=i*m+j;
                int temp=ds.findUpar(node);
                if(notvalid(i,j,n,m)){
                    visited[temp]=1;
                }

            }
        }
        int cnt=0;
       for(int i=0;i<n*m;i++){
        if(grid[i/m][i%m]==0 && visited[i]==0 && ds.findUpar(i)==i)
        cnt++;
       }
       return cnt;
    }
};