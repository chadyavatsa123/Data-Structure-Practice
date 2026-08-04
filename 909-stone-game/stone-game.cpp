class Solution {
public:
// example [2 3 4 5 6 1]
//alice -> 2 [3 4 5 6 1]
//bob -> 3 [4 5 6 1]
//alice -> 4
//bob-> 5
//alice ->6
//bob ->1

    int rec(int i,int j,vector<int>&nums){
        if(i==j){
            return nums[i];

        }
        int left = nums[i] - rec(i+1,j,nums);
        int right = nums[j] - rec(i,j-1,nums);

        return max(left,right);
    }
    int solve(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i==j){
            return nums[i];

        }
        if(dp[i][j]!=-1) return dp[i][j];
        int left = nums[i] - solve(i+1,j,nums,dp);
        int right = nums[j] - solve(i,j-1,nums,dp);

        return dp[i][j] = max(left,right);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        //return rec(0,n-1,piles)>0;
        return solve (0,n-1,piles,dp)>0;
    }
};