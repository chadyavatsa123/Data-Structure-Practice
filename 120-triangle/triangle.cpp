class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& triangle,int n,vector<vector<int>>&dp
    ,vector<vector<bool>>&visited){
        if(row==n-1)return triangle[row][col];
        if(visited[row][col]==true)return dp[row][col];
        visited[row][col]=true;
        int down=triangle[row][col]+solve(row+1,col,triangle,n,dp,visited);
        int dgn=triangle[row][col]+solve(row+1,col+1,triangle,n,dp,visited);
        return dp[row][col]= min(down,dgn);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
       vector<vector<int>>dp(n,vector<int>(n,0));
       vector<vector<bool>>visited(n,vector<bool>(n,false));
       return  solve(0,0,triangle,n,dp,visited);
    }
};