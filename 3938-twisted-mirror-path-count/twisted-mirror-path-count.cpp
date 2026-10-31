class Solution{
public:
    const int MOD = 1e9 + 7;
vector<vector<int>>dp;
   vector<vector<vector<int>>> memo;
   // vector<vector<int>> dp;
  //  vector<vector<vector<int>>> memo;

    int n, m;
    //vector<vector<int>>* g;

    // Robot is standing on an empty cell
    int solve(int row, int col,vector<vector<int>>&grid) {

        if (row == n - 1 && col == m - 1)
            return 1;

        if (dp[row][col] != -1)
            return dp[row][col];

        long long down = enter(row + 1, col, 1,grid);
        long long right = enter(row, col + 1, 0,grid);

        return dp[row][col] = (down + right) % MOD;
    }

    // dir = 0 means RIGHT
    // dir = 1 means DOWN
    int enter(int row, int col, int dir,vector<vector<int>>&grid) {

        if (row >= n || col >= m)
            return 0;

        if (memo[row][col][dir] != -1)
            return memo[row][col][dir];

        // Mirror found
        if (grid[row][col] == 1) {

            if (dir == 0) {
                // Moving RIGHT -> reflected DOWN
                return memo[row][col][dir] =
                    enter(row + 1, col, 1,grid);
            }
            else {
                // Moving DOWN -> reflected RIGHT
                return memo[row][col][dir] =
                    enter(row, col + 1, 0,grid);
            }
        }

        // Empty cell: robot can choose either direction
        return memo[row][col][dir] = solve(row, col,grid);
    }

    int uniquePaths(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

       // g = &grid;

       // dp.assign(n, vector<int>(m, -1));
    dp.assign(n, vector<int>(m, -1));
    memo.assign(n, vector<vector<int>>(m, vector<int>(2, -1)));
        return solve(0, 0,grid);
    }
    };