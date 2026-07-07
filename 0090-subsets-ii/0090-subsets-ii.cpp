class Solution {
public:

        void solve(int index,vector<int>& nums,vector<int>& output , vector<vector<int>>&ans){
           //base case
           if(index==nums.size()){
            ans.push_back(output);
            return;
           } 
           //now include the term
          
           output.push_back(nums[index]);

            solve(index+1,nums,output,ans);
            output.pop_back();
            // now exclude duplicies
            while(index+1<nums.size()&& nums[index]==nums[index+1]){
                index++;
            }
             solve(index+1,nums,output,ans); // ya initialize important ha
        }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
// sort it
        sort(nums.begin(),nums.end());

        int index=0;
        vector<int> output;
        vector<vector<int>> ans;

        solve(0,nums,output,ans);
        return ans;
    }
};