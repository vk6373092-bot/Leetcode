class Solution {
public:
        void solve(int index,int k,int target,vector<int>&temp, vector<vector<int>>& ans){
            if(index>9  ){
                if(target==0&& temp.size()==k)
                ans.push_back(temp);
                return;

            }
            if(index<=target){
                temp.push_back(index);

                solve(index+1,k,target-index,temp,ans);
                //backtracking
                temp.pop_back();
            }
            solve(index+1,k,target,temp,ans);
        }

    vector<vector<int>> combinationSum3(int k, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(1,k,target,temp,ans);
         return ans;
    }
   
};