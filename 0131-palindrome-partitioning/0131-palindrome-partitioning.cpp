class Solution {
public:

        bool ispalindrome(string &s, int left,int right){
            while(left<right){
                if(s[left]!=s[right]){
                    return false;
                }
                    left++;
                    right--;
                
            }
              return true;
        }

        void solve(int index,string &s, vector<string>& temp,vector<vector<string>> &ans) {
            //base case
            if(index==s.size()){
                ans.push_back(temp);
                return ;
            }

        // now make possible substring
            for(int i=index;i<s.size();i++){
            if(ispalindrome(s,index,i)){ // as yahi chaiya
                temp.push_back(s.substr(index,i-index+1));
                solve(i+1,s,temp,ans);
                // backtracking
                temp.pop_back();
            }
        }
        }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>>ans;
        solve(0,s,temp,ans);
        return ans;
    }
};