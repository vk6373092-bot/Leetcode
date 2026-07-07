class Solution {
public:

        void solve(int n , string curr ,vector<string> & ans){
            // base case
            if(curr.length()==n){
                ans.push_back(curr);
                return;
            }
            // print as 1
            solve(n,curr+'1',ans);
            // solve for zero
            if(curr.empty()||curr.back()=='1'){
                solve(n,curr+'0',ans);
            }
        }
    vector<string> validStrings(int n) {
        vector<string>ans;
        solve(n,"",ans);
        return ans;
        
    }
};