class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&visited,int drow[],int dcol[],vector<vector<char>>&board,
    int n,int m){
        visited[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && visited[nrow][ncol]==0)
            dfs(nrow,ncol,visited,drow,dcol,board,n,m);
        }

    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && visited[0][i]==0)
                dfs(0,i,visited,drow,dcol,board,n,m);
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && visited[i][0]==0)
            dfs(i,0,visited,drow,dcol,board,n,m);
        }
        for(int i=0;i<m;i++){
            if(board[n-1][i]=='O' && visited[n-1][i]==0)
            dfs(n-1,i,visited,drow,dcol,board,n,m);
        }
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O' && visited[i][m-1]==0)
            dfs(i,m-1,visited,drow,dcol,board,n,m);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && visited[i][j]==0)
                board[i][j]='X';
            }
        }
    }
};