class Solution {
public:

       void solve(int index,vector<int>& candidates,int target,vector<int>& temp , vector<vector<int>>&ans){
            if(index==candidates.size()){
                if(target==0)
                ans.push_back(temp);
            
            return;
        }
        //set up operations
        if(candidates[index]<=target){
            temp.push_back(candidates[index]);

            //reuse the current element
            solve(index,candidates,target-candidates[index],temp,ans);
            //for back_tracking
            temp.pop_back();

        }
        solve(index+1,candidates,target,temp,ans);
        }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<int> temp;
        vector<vector<int>>ans;
        solve(0,candidates,target,temp,ans);
        return ans;
    }
};