class Solution {
public:
    bool isSafe(int row , int col , vector<vector<int>> &board , int n){
    int x = row;
    int y = col;
    while(y >= 0){
        if(board[x][y] == 1)
            return false;
        y--;
    }
    x = row;
    y = col;
    while(x>=0 && y >= 0){
        if(board[x][y] == 1)
            return false;
        y--;
        x--;
    }
    x = row;
    y = col;
    while(x<n && y >= 0){
        if(board[x][y] == 1)
            return false;
        y--;
        x++;
    }
    return true;
}

void solve(int col , vector<vector<int>> &ans , vector<vector<int>> &board , int n , int &count){
    if(col == n){
        count++;
        return ;
    }
    
    for(int row = 0 ; row < n ; row++){
        if(isSafe(row,col,board,n)){
            board[row][col] = 1;
            solve(col+1 , ans , board , n , count);
            board[row][col] = 0;
        }
    }
}

    int totalNQueens(int n) {
        vector<vector<int>> board(n , vector<int>(n,0));
        vector<vector<int>> ans;
        int count = 0;
        solve(0 , ans , board , n , count);
        return count;
    }
};