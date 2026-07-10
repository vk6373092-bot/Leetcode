class Solution {
public:
    bool solve(int index,vector<vector<char>>& board, string &word,int i,int j){
        if(index==word.size()){
            return true;
        }
        //when false
        if(i<0||j<0||board.size()<=i||board[0].size()<=j||board[i][j]!=word[index]){
            return false;
        }
        // now make an index of board
        char ch=board[i][j];
            board[i][j]='#';

            bool found=solve(index+1,board,word,i+1,j)||
                        solve(index+1,board,word,i-1,j)||
                        solve(index+1,board,word,i,j+1)||
                        solve(index+1,board,word,i,j-1);

                    // backtracking
                    board[i][j]=ch;
                    return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
            int m=board.size();
            int n=board[0].size();
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]==word[0]){
                        if(solve(0,board,word,i,j)){
                            return true;
                        }
                    }
                }
            }
            return false;
    }
};