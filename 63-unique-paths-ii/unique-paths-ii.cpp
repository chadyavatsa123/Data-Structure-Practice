class Solution {
public:
    int func(int row,int col,vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp){
        if(row==0 && col==0){
            return obstacleGrid[row][col]==0?1:0;
        }
        if(row<0 || col<0)return 0;
        
        if(dp[row][col]!=-1)return dp[row][col];
        int up=0;
        int left=0;
        if(row>0 && obstacleGrid[row-1][col]==0)
         up=func(row-1,col,obstacleGrid,dp);
        if( col>0 && obstacleGrid[row][col-1]==0)
         left=func(row,col-1,obstacleGrid,dp);
        return dp[row][col]=up+left;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1)return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(n-1,m-1,obstacleGrid,dp);
    }
};