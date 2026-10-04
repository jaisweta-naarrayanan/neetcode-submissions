class Solution {
public:
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    void dfs(vector<vector<char>>& board, int i, int j, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m || board[i][j] != 'O') return;
        if(board[i][j] == 'O')
            board[i][j] = 'S';
        
        for(int k=0; k<4; k++){
            int ni = i+dx[k];
            int nj = j+dy[k];
            dfs(board, ni, nj, n, m);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(), m = board[0].size();
        for(int i=0; i<n; i++){
            dfs(board, i, 0, n, m); 
            dfs(board, i, m-1, n, m);
        }
        for(int j=0; j<m; j++){
            dfs(board, 0, j, n, m); 
            dfs(board, n-1, j, n, m);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                board[i][j] = (board[i][j] == 'S')? 'O': 'X'; 
            }
        }
    }
};
