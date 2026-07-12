class Solution {
public:
        bool issafe(vector<vector<char>>& board, int row,int column,char ch){
            for(int j=0;j<9;j++){
                if(board[row][j]==ch){
                     return false;
                }
               
            }
            // now vertical
            for(int i=0;i<9;i++){
                if(board[i][column]==ch){

                
                return false;
                }
                     }
                     // now important grid
                     int start=(row/3)*3;
                     int last=(column/3)*3;
                     for(int i=start;i<start+3;i++){
                        for(int j=last;j<last+3;j++){
                          if(  board[i][j]==ch){

                          
                            return false;
                          }
                        }
                     }
                     return true;
        }
         bool solve(vector<vector<char>>& board){
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    // now check which is the first position which is blank
                    if(board[i][j]=='.'){
                        for(char ch='1';ch<='9';ch++){
                            if(issafe(board,i,j,ch)){
                                board[i][j]=ch;

                                // if it is solved
                                if(solve(board))
                                    return true;

                                    // backtracking 
                                    board[i][j]='.';
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