class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>diff(n,vector<int>(m,INT_MAX));
      priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        diff[0][0]=0;
        pq.push({0,{0,0}});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diffi=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1 && col==m-1)return diffi;
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){
                  if(diff[nrow][ncol]>max(abs(heights[nrow][ncol]-heights[row][col]),diffi)){
                    diff[nrow][ncol]=max(abs(heights[nrow][ncol]-heights[row][col]),diffi);
                    pq.push({diff[nrow][ncol],{nrow,ncol}});
                  }
                }
            }

        }
        return -1;
    }
};