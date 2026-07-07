class Solution {
public:

        void solve(int index,vector<int>& nums , vector<int>& output ,vector<vector<int>> &ans ){
            //base case
            if(index==nums.size()){
                ans.push_back(output);
                return;
            }
            solve(index+1,nums,output,ans);
            // we include that no.
            output.push_back(nums[index]);

          solve(index+1,nums,output,ans);
          //back tracking
          output.pop_back();

        }

    vector<vector<int>> subsets(vector<int>& nums) {
        int index;
        vector<int> output;
        vector<vector<int>>ans;
        solve(index,nums,output,ans);
        return ans;
    }
};