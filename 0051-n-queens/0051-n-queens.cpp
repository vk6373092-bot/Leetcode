class Solution {
public:

        bool issafe(vector<string> &board , int row, int column, int n){
            // for horizontal
            for(int j=0;j<n;j++){
                if(board[row][j]=='Q'){
                    return false;
                }
            }
            //for vertical
            for(int i=0;i<n;i++){
                if(board[i][column]=='Q'){
                    return false;
                }
            }
            // for left diagonal
            for(int i=row,j=column;j>=0&& i>=0;i--,j--){
               if(board[i][j]=='Q'){
                return false;
               }
                
            }
                // for right diagonal
                for(int i=row,j=column;i>=0&&j<n;i--,j++){
                    if(board[i][j]=='Q'){
                        return false;
                    }
                }

                return true;
        }

        void NQueens(vector<string> &board, int n, int row,vector<vector<string>> &ans){
            //base case
            if(row==n){
                ans.push_back(board);
                return;
            }
            //check which row is suitable
            for(int j=0;j<n;j++){
                if(issafe( board, row,j,n)){
                    board[row][j]='Q';
                    NQueens(board,n,row+1,ans);
                    board[row][j]='.';

                    
                }
            }
        }
    vector<vector<string>> solveNQueens(int n) {
            vector<string>board(n,string(n,'.'));  // important see as each board have empty space 
         vector<vector<string>> ans;
        NQueens(board,n,0,ans);
         return ans;
    }
};