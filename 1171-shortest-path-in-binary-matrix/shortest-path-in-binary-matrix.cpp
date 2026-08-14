class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,pair<int,int>>>q;
        
        dist[0][0]=1;
        q.push({1,{0,0}});
        while(!q.empty()){
            int dis=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            if(row==n-1 && col==n-1)return dis;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                  int nrow=row+i;
                  int ncol=col+j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 &&
                    dist[nrow][ncol]>dis+1){
                        dist[nrow][ncol]=dis+1;
                        q.push({dist[nrow][ncol],{nrow,ncol}});
                    }

                }
            }

        }
        return -1;
    }
};