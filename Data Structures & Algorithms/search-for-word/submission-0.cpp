class Solution {
public:
    bool backtract(vector<vector<char>>& board,int idx, int i, int j, int n, int m, string word){
        if(idx == word.size())
            return true;
        if(i<0 || i>=n || j<0 || j>=m || board[i][j] != word[idx] || board[i][j] == '#'){
            return false;
        }
        //if(board[i][j] != word[idx]) return false;

        //char temp = board[i][j];
        board[i][j] = '#';
        bool found =  backtract(board, idx+1, i+1, j, n, m, word) || 
                backtract(board, idx+1, i, j+1, n, m, word)||
                backtract(board, idx+1, i-1, j, n, m, word) || 
                backtract(board, idx+1, i, j-1, n, m, word);
        board[i][j] = word[idx];
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0] && backtract(board,0,i,j,n,m,word))
                    return true;
            }
        }
        //return backtract(board,0,0,0,n,m,word);
        return false;
    }
};
