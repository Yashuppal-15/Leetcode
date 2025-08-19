class Solution {
public:
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};
    void dfs(int i , int j ,vector<vector<int>>& vis , vector<vector<char>> & board){
        int n = board.size();
        int m = board[0].size();
        vis[i][j]=1;

        for(int k=0;k<4;k++){
            int x= dx[k]+i;
            int y= dy[k]+j;
            if( x>=0 && x<n && y>=0 && y<m && !vis[x][y] && board[x][y]=='X'){
                dfs(x,y,vis, board);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;

        for(int i=0;i<n ;i++){
            for(int j=0;j <m ;j++){
                if(!vis[i][j] && board[i][j]=='X'){
                    dfs(i,j,vis, board);
                    count++;
                }
            }
        }
        return count;
    }
};