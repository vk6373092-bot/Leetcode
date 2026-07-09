class Solution {
public:

    void solve(int index,vector<int>& candidates, int target,vector<int>& temp, vector<vector<int>>& ans ){
        //base case
        if(index==candidates.size()){
            if(target==0)
                ans.push_back(temp);

                return;
        }
            if(candidates[index]<=target){
                temp.push_back(candidates[index]);
                solve(index+1,candidates,target-candidates[index],temp,ans);
                temp.pop_back();

            }
            //skip the duplicates
            int next= index+1;
            while(next<candidates.size()&&candidates[next]==candidates[index]){
                next++; // why index+1 because to get rid fron duplicies 
            }
            solve(next,candidates,target,temp,ans);
        }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        solve(0,candidates,target,temp,ans);
        return ans;
    }
};