class Solution {
public:
// good call is put const in mapping inside solve()
        void solve(int index,string &digits,string &temp,const vector<string>&mapping ,vector<string>& ans){
           //base case
            if(index==digits.size()){
                ans.push_back(temp);
                return;
            }
                

            string letters=mapping[digits[index]-'0']  ;

            // we use each element
            for(char ch:letters){
                temp.push_back(ch);
                solve(index+1,digits,temp,mapping,ans);
                // now backtrack
                temp.pop_back();
            }     


        }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()){
            return ans;
        }
        vector<string>mapping={
            "",        //0
            "",         //1
             "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        string temp="";

        solve(0,digits,temp,mapping,ans);
            return ans;
    }
};