class Solution {
public:
    class DisjointSet{
        public:
        vector<int>parent,size;
        vector<long long>sum;
        DisjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1);
            sum.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;

            }
        }
           int findUpar(int node){
            if(node==parent[node])return node;
            return parent[node]=findUpar(parent[node]);
           }
           void unionBySize(int u,int v){
            int ulp_u=findUpar(u);
            int ulp_v=findUpar(v);
            if(ulp_u==ulp_v)return;
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
                sum[ulp_v]+=sum[ulp_u];
            }
            else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
                sum[ulp_u]+=sum[ulp_v];
            }
           }
           
        
    };
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        DisjointSet ds(n*m);
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            int node=i*m+j;
            ds.sum[node]=grid[i][j];
          }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)continue;
                int drow[]={-1,0,1,0};
                int dcol[]={0,1,0,-1};
                for(int ind=0;ind<4;ind++){
                    int nrow=i+drow[ind];
                    int ncol=j+dcol[ind];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]!=0){
                        int node=i*m+j;
                        int newnode=nrow*m+ncol;
                       ds.unionBySize(node,newnode);
                     
                    }
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n*m;i++){
            if(grid[i/m][i%m]!=0 && i==ds.findUpar(i) && ds.sum[ds.findUpar(i)]%k==0)
            cnt++;
        }
        return cnt;
    }
};