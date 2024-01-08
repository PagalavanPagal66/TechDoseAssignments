class Solution {
public:
    bool valid(vector<vector<char>>& board,int i,int j,char c){
        for(int it=0;it<9;it++){
            if(board[i][it]==c){
                return false;
            }
            if(board[it][j]==c){
                return false;
            }
            if(board[3*(i/3)+it/3][3*(j/3)+it%3]==c){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char a='1';a<='9';a++){
                        if(valid(board,i,j,a)){
                            board[i][j]=a;
                            if(solve(board)){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};